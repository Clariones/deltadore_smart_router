package codegen.fdti.cpp;

import java.io.File;
import java.util.HashMap;
import java.util.Map;

import freemarker.template.Template;

public class CommandUIGenerator extends BaseGenerator {

	@Override
	public void run() throws Exception {
		beforeRun();
		File outputFolder = new File(getConfig().getOutputFolder());

		Map<String, Object> data = new HashMap<>();
		data.put("orignal_cfg", config.getConfigs());
		HashMap<String, Map> commandCfg = new HashMap<>();
		data.put("commands", commandCfg);
		prePareDate(data, null);
		for (CommandConfig cmdCfg : config.getConfigs()) {
			HashMap<String, Object> cmdParam = new HashMap<>();
			cmdParam.put("cmd_name", getCamelName(cmdCfg.getName()));
			cmdParam.put("cmd_result_handler", cmdCfg.getResultUiHandling());
			cmdParam.put("cmd_dscp", cmdCfg.getDescription());
			commandCfg.put(cmdCfg.getName(), cmdParam);
		}

		// ui page
		Template template = this.freemarkerCfg.getTemplate("webUiPage.jstl");
		String fileName = "webui/web_ui_page.html";
		doGeneration(outputFolder, fileName, template, data);

		// Chinese I18N
		template = this.freemarkerCfg.getTemplate("webUi18n.jstl");
		fileName = "webui/chinese.js";
		doGeneration(outputFolder, fileName, template, data);
		// English I18N
		template = this.freemarkerCfg.getTemplate("webUiName.jstl");
		fileName = "webui/english.js";
		doGeneration(outputFolder, fileName, template, data);
		afterRun();
	}

	@Override
	protected void prePareDate(Map<String, Object> data, CommandConfig cmdCfg)
			throws Exception {
		HashMap<String, String> names = new HashMap<>();
		names.put("selectOneCommand", "请选择一个命令");
		names.put("queryLightStatus", "查询灯光状态");
		names.put("setNodeName", "设置节点名称");
		names.put("queryRollerShutterInfo", "查询窗帘设备信息");
		names.put("controlLight", "控制灯光设备");
		names.put("getTopology", "查询所有设备状态");
		names.put("queryLightColor", "查询灯光颜色");
		names.put("setNetworkName", "设置区域名称");
		names.put("deleteNode", "删除一个设备");
		names.put("registerNode", "注册一个设备");
		names.put("queryRollerShutterStatus", "查询窗帘状态");
		names.put("queryLightInfo", "查询灯光设备信息");
		names.put("controlRollerShutter", "控制窗帘");
		names.put("controlLightColor", "设置灯光颜色");
		names.put("forceRefreshTopology", "强制刷新所有设备状态");
		data.put("command_naming", names);
		
		names = new HashMap<>();
		names.put("selectOneCommand", "请选择一个命令");
		names.put("queryLightStatus", "查询灯光设备的状态");
		names.put("setNodeName", "设置一个指定区域内的设备的名字");
		names.put("queryRollerShutterInfo", "查询窗帘设备的厂家信息");
		names.put("controlLight", "控制灯光设备的状态");
		names.put("getTopology", "查询当前的所有设备状态");
		names.put("queryLightColor", "查询灯光设备的颜色信息");
		names.put("setNetworkName", "设置一个区域的名称");
		names.put("deleteNode", "删除一个指定的设备");
		names.put("registerNode", "注册一个设备到指定的区域");
		names.put("queryRollerShutterStatus", "查询窗帘设备的状态");
		names.put("queryLightInfo", "查询灯光设备的厂家信息");
		names.put("controlRollerShutter", "控制窗帘的位置");
		names.put("controlLightColor", "设置灯光设备的颜色");
		names.put("forceRefreshTopology", "清楚缓存，强制刷新所有设备状态");
		data.put("command_dscp", names);
	}

	@Override
	protected String getOutputFileName(CommandConfig cmdCfg) throws Exception {
		return null;
	}

	@Override
	protected Template getTemplate(CommandConfig cmdCfg) throws Exception {
		return null;
	}

}
