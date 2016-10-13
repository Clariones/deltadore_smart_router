package codegen.fdti.cpp;

import java.util.Map;
import java.util.regex.Matcher;
import java.util.regex.Pattern;

import freemarker.template.Template;

public class HeaderFileGenerator extends BaseGenerator{

	@Override
	protected String getOutputFileName(CommandConfig cmdCfg) throws Exception {
		String cmdName = getCamelName(cmdCfg.getName());
		return getConfig().getSubFolder() + "/Cmd" + capFirst(cmdName) + "Handler.h";
	}

	@Override
	protected Template getTemplate(CommandConfig cmdCfg) throws Exception {
		return this.freemarkerCfg.getTemplate("Handler.h.jstl");
	}

	@Override
	protected void prePareDate(Map<String, Object> data, CommandConfig cmdCfg)
			throws Exception {
		String cmdName = getCamelName(cmdCfg.getName());
		data.put("command_name", cmdName);
		data.put("h_file_name", "Cmd" + capFirst(cmdName) + "Handler.h");
		data.put("file_name", "Cmd" + capFirst(cmdName) + "Handler.cpp");
		data.put("class_name", "Cmd" + capFirst(cmdName) + "Handler");
	}

}
