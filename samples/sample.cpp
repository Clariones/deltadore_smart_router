
/*
With the C++ version, the usage is the same as Java.
Please, refer to the Java documentation to get more informations.

Prerequisite for serial communication :
*/

class SerialInputStream : public InputStream
{
  public:
    SerialInputStream();
    ~SerialInputStream();

    int read(void* buffer, int size);
    void close();

  private:
    int m_tty;
}

class SerailOutputStream : public OutputStream
{
  public:
    SerialOutputStream();
    ~SerialOutputStream();

    int write(void* buffer, int size);
    void close();

  private:
    int m_tty;
}

SerialInputStream::SerialInputStream()
{
  struct termios termOptions;
  m_tty = open("/dev/ttyUSB0", O_RDONLY|O_NOCTTY|O_NONBLOCK);
  tcgetattr(m_tty, &termOptions);
  termOptions.c_cflag |= (CLOCAL | CREAD);
  termOptions.c_cflag &= ~PARENB;
  termOptions.c_cflag &= ~CSTOPB;
  termOptions.c_cflag &= ~CSIZE;
  termOptions.c_cflag |= CS8;
  termOptions.c_lflag &= ~(ICANON | ECHO | ISIG);
  cfsetispeed( &termOptions, B38400 );
  cfsetospeed( &termOptions, B38400 );
  tcsetattr( m_tty, TCSADRAIN, &termOptions );
}

SerialInputStream::~SerialInputStream()
{
}

int SerialInputStream::read(void* buffer, int size)
{
  return read(m_tty, buffer, size);
}

void SerialInputStream::close()
{
  close(m_tty);
}

SerialOutputStream::SerialOutputStream()
{
  struct termios termOptions;
  m_tty = open("/dev/ttyUSB0", O_RDWR|O_NOCTTY);
  tcgetattr(m_tty, &termOptions);
  termOptions.c_cflag |= (CLOCAL | CREAD);
  termOptions.c_cflag &= ~PARENB;
  termOptions.c_cflag &= ~CSTOPB;
  termOptions.c_cflag &= ~CSIZE;
  termOptions.c_cflag |= CS8;
  termOptions.c_lflag &= ~(ICANON | ECHO | ISIG);
  cfsetispeed( &termOptions, B38400 );
  cfsetospeed( &termOptions, B38400 );
  tcsetattr( m_tty, TCSADRAIN, &termOptions );
}

SerialOutputStream::~SerialOutputStream()
{
}

int SerialOutputStream::write(void* buffer, int size)
{
  return write(m_tty, buffer, size);
}

void SerialOutputStream::close()
{
  close(m_tty);
}

/*
 * Initialization :
 */
Controller *ctrl = Factory::createController();
ctrl->addAcknowledgmentListener(this);
MeshController *meshctrl = ctrl->convert<MeshContoller*>();
meshctrl->addEndTransactionListener(this);
meshctrl->addNodeDiscoveredListener(this);
SerialInputStream *iStream = new SerialInputStream();
SerialOutputStream *oStream = new SerialOutputStream();
ctrl->open(iStream, oStream);
meshctrl->initNetworks();

/*
 * How to send a request :
 */
Request *req = meshctrl->createRequest(RollerShutterCommandRequest_t);
Network *net = meshctrl->getNetwork(0);
req->setNetwork(net);
req->addNode(Node::NODE0, RollerShutterCommandArg::UP);
req->addNode(Node::NODE1, RollerShutterCommandArg::DOWN);
meshctrl->begintransaction(req);
delete(req);

/*
 * How to get results with the EndTransactionListener event handler :
 */
void MyClass::endTransaction(const EndTransaction& evt)
{
  std::vector<Node> nodes = evt.getRequest()->nodes();
  std::vector<Node>::iterator it;
  for (it = nodes.begin(); it != nodes.end(); it++)
  {
    Node node = *it;
    Response *resp = evt.getResponse(node)->clone();
    if (resp->getStatus() == ResponseStatus::OK)
    {
      if (resp->instanceof(RollerShutterStatusResponse_t))
      {
        RollerShutterStatusResponse *shutterResp = resp->convert<RollerShutterStatusResponse*>();
        int shutterPosition = shutterResp->getPosition();
        // TO DO with the position value
      }
    }
  }
}


