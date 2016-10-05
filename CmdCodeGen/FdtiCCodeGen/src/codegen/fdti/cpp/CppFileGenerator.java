package codegen.fdti.cpp;

import java.util.Map;
import java.util.regex.Matcher;
import java.util.regex.Pattern;

import freemarker.template.Template;

public class CppFileGenerator extends BaseGenerator{

	@Override
	protected String getOutputFileName(CommandConfig cmdCfg) throws Exception {
		String cmdName = getCamelName(cmdCfg.getName());
		return getConfig().getSubFolder() + "/Cmd" + capFirst(cmdName) + "Handler.cpp";
	}

	@Override
	protected Template getTemplate(CommandConfig cmdCfg) throws Exception {
		switch (cmdCfg.getTemplate()){
		case "ApiMapping":
			return this.freemarkerCfg.getTemplate("ApiMapping.cpp.jstl");
		case "SimpleApi":
			return this.freemarkerCfg.getTemplate("SimpleApi.cpp.jstl");
		case "NetworkApi":
			return this.freemarkerCfg.getTemplate("NetworkApi.cpp.jstl");
		}
		throw new RuntimeException("Unsupported template type: " + cmdCfg.getTemplate());
	}

	@Override
	protected void prePareDate(Map<String, Object> data, CommandConfig cmdCfg)
			throws Exception {
		String cmdName = getCamelName(cmdCfg.getName());
		data.put("command_name", cmdName);
		data.put("h_file_name", "Cmd" + capFirst(cmdName) + "Handler.h");
		data.put("file_name", "Cmd" + capFirst(cmdName) + "Handler.cpp");
		data.put("class_name", "Cmd" + capFirst(cmdName) + "Handler");
		switch (cmdCfg.getTemplate()){
		case "ApiMapping":
			prePareDateForApiMapping(data, cmdCfg);
			break;
		case "SimpleApi":
			prePareDateForSimpleApi(data, cmdCfg);
			break;
		case "NetworkApi":
			prePareDateForNetworkApi(data, cmdCfg);
			break;
		default:
			throw new RuntimeException("Unsupported template type: " + cmdCfg.getTemplate());
		}
		
	}

	private void prePareDateForNetworkApi(Map<String, Object> data,
			CommandConfig cmdCfg) {
		StringBuilder sb = new StringBuilder();
		fillNetworkUsage(cmdCfg, sb);
		data.put("usage", formatUsageOutput(sb));
	}

	private void prePareDateForSimpleApi(Map<String, Object> data,
			CommandConfig cmdCfg) {
		Object[] params = cmdCfg.getParams();
		if (params == null){
			throw new RuntimeException(cmdCfg.getName()+" has no params defined");
		}
		data.put("usage", getSimpleApiUsage(cmdCfg));
	}

	private String getSimpleApiUsage(CommandConfig cmdCfg) {
		StringBuilder sb = new StringBuilder();
		
		fillNetworkUsage(cmdCfg, sb);
		Object[] params = cmdCfg.getParams();
		for(Object param : params){
			Map<String, Object> paramInfo = (Map<String, Object>) param;
			sb.append(" <").append(paramInfo.get("paramName")).append('>');
		}
		sb.append("\\n");
		sb.append("Params:\\n");
		if (cmdCfg.hasNetwork){
			sb.append("    network: the network number of target device, 0~11\\n");
		}
		if (cmdCfg.hasNode){
			sb.append("    node: the node number of target device, 0~15\\n");
		}
		for(int i =0; i< params.length; i++){
			
			Map<String, Object> paramInfo = (Map<String, Object>)params[i];
			sb.append("    ").append(paramInfo.get("paramName")).append(": ").append(paramInfo.get("note"));
			if (i < params.length - 1){
				sb.append("\\n");
			}
		}

		return formatUsageOutput(sb);
	}

	private void fillNetworkUsage(CommandConfig cmdCfg, StringBuilder sb) {
		String cmdName = getCamelName(cmdCfg.getName());
		sb.append("Usage:\\n");
		sb.append("    ").append(cmdName);
		if (cmdCfg.hasNetwork){
			sb.append(" <network>");
		}
		if (cmdCfg.hasNode){
			sb.append(" <node>");
		}
	}

	private void prePareDateForApiMapping(Map<String, Object> data,
			CommandConfig cmdCfg) {
		Map<String, Object> apiMapping = cmdCfg.getMapping();
		if (apiMapping == null){
			throw new RuntimeException(cmdCfg.getName()+" has no mapping defined");
		}
		data.put("max_map_param_length", getMaxMapParamLength(cmdCfg));
		data.put("usage", getApiMappingUsage(cmdCfg));
	}

	private String getApiMappingUsage(CommandConfig cmdCfg) {
		StringBuilder sb = new StringBuilder();
		fillNetworkUsage(cmdCfg, sb);
		sb.append(' ').append(cmdCfg.getParamName()).append("\\n");
		sb.append("Params:\\n");
		if (cmdCfg.hasNetwork){
			sb.append("    network: the network number of target device, 0~11\\n");
		}
		if (cmdCfg.hasNode){
			sb.append("    node: the node number of target device, 0~15\\n");
		}
		sb.append("    ").append(cmdCfg.getParamName()).append(": the valid action options. Can be:\\n");
		sb.append("       ");
		for(String name : cmdCfg.getMapping().keySet()){
			sb.append(' ').append(name);
		}
		return formatUsageOutput(sb);
	}

	private String formatUsageOutput(StringBuilder sb) {
		String usage = sb.toString();
		usage = usage.replace("\\n", "\\n\" \\\n        \"");
		return usage.trim();
	}

	private Object getMaxMapParamLength(CommandConfig cmdCfg) {
		Map<String, Object> apiMapping = cmdCfg.getMapping();
		
		int maxLength = 10;
		for(String name : apiMapping.keySet()){
			maxLength = Math.max(maxLength, name.length());
		}
		return maxLength+1;
	}

}
