package codegen.fdti.cpp;

import java.io.File;
import java.io.FileReader;

import com.google.gson.Gson;

public class Main {

	public static void main(String[] args) throws Exception {
		String fileName = "testinput/command.def.json";
		FileReader fReader = new FileReader(new File(fileName));
		Config config = new Gson().fromJson(fReader, Config.class);
		
		BaseGenerator cppWorker = new CppFileGenerator();
		cppWorker.setConfig(config);
		cppWorker.run();
	}

	
	static public class  Config{
		CommandConfig[] configs;
		String subFolder;
		String outputFolder;
		String templateBaseFolder;

		public String getTemplateBaseFolder() {
			return templateBaseFolder;
		}

		public void setTemplateBaseFolder(String templateBaseFolder) {
			this.templateBaseFolder = templateBaseFolder;
		}

		public String getOutputFolder() {
			return outputFolder;
		}

		public void setOutputFolder(String outputFolder) {
			this.outputFolder = outputFolder;
		}

		public String getSubFolder() {
			return subFolder;
		}

		public void setSubFolder(String subFolder) {
			this.subFolder = subFolder;
		}

		public CommandConfig[] getConfigs() {
			return configs;
		}

		public void setConfigs(CommandConfig[] configs) {
			this.configs = configs;
		}
		
	}
}
