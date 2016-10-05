package codegen.fdti.cpp;

import java.io.File;
import java.io.FileWriter;
import java.util.HashMap;
import java.util.Map;

import codegen.fdti.cpp.Main.Config;
import freemarker.template.Configuration;
import freemarker.template.Template;

public abstract class BaseGenerator {
	protected Config config;
	protected Configuration freemarkerCfg;

	public Config getConfig() {
		return config;
	}

	public void setConfig(Config config) {
		this.config = config;
	}

	public void run() throws Exception {
		beforeRun();
		File outputFolder = new File(getConfig().getOutputFolder());
		for(CommandConfig cmdCfg : config.getConfigs()){
			Template template = getTemplate(cmdCfg);
			String fileName = getOutputFileName(cmdCfg);
			Map<String, Object> data = new HashMap<>();
			data.put("command_config", cmdCfg);
			prePareDate(data, cmdCfg);
			doGeneration(outputFolder, fileName, template, data);
		}
		afterRun();
	}

	protected void afterRun() throws Exception{
		// by default, nothing to do		
	}

	protected void doGeneration(File outputFolder, String fileName,
			Template template, Map<String, Object> data) throws Exception {
		File outputFile = new File(outputFolder, fileName);
		File outputFileDirectory = outputFile.getParentFile();
		if (!outputFileDirectory.exists()){
			outputFileDirectory.mkdirs();
		}
		if (!outputFile.exists()){
			outputFile.createNewFile();
		}
		FileWriter out = new FileWriter(outputFile);
		template.process(data, out);
		out.flush();
		out.close();
	}

	protected abstract void prePareDate(Map<String, Object> data, CommandConfig cmdCfg) throws Exception;

	protected abstract String getOutputFileName(CommandConfig cmdCfg) throws Exception;

	protected abstract Template getTemplate(CommandConfig cmdCfg) throws Exception;

	protected void beforeRun() throws Exception{
		// by default, create configuration
		Configuration cfg = new Configuration(Configuration.VERSION_2_3_23);
		cfg.setDefaultEncoding("UTF-8");
		cfg.setDirectoryForTemplateLoading(new File(config.getTemplateBaseFolder()));
		this.freemarkerCfg = cfg;
	}

	protected String getCamelName(String name) {
		StringBuilder sb = new StringBuilder();
		String[] namePieces = name.trim().split("[ _\\-\\.]+");
		sb.append(namePieces[0].toLowerCase());
		for(int i=1;i<namePieces.length;i++){
			sb.append(capFirst(namePieces[i].toLowerCase()));
		}
		return sb.toString();
	}

	protected String capFirst(String str) {
		return Character.toUpperCase(str.charAt(0)) + str.substring(1);
	}
	
	

}
