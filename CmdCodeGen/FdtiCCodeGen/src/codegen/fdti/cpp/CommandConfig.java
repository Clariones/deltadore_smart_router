package codegen.fdti.cpp;

import java.util.Map;

public class CommandConfig {
	protected String name;
	protected String template;
	protected String description;
	protected String apiName;
	protected boolean hasNetwork;
	protected boolean hasNode;
	protected String paramName;
	protected Map<String, Object> mapping;
	protected Object[] params;
	protected String resultUiHandling;
	
	public String getResultUiHandling() {
		return resultUiHandling;
	}
	public void setResultUiHandling(String resultUiHandling) {
		this.resultUiHandling = resultUiHandling;
	}
	public String getName() {
		return name;
	}
	public void setName(String name) {
		this.name = name;
	}
	public String getTemplate() {
		return template;
	}
	public void setTemplate(String template) {
		this.template = template;
	}
	public String getDescription() {
		return description;
	}
	public void setDescription(String description) {
		this.description = description;
	}
	public String getApiName() {
		return apiName;
	}
	public void setApiName(String apiName) {
		this.apiName = apiName;
	}
	public boolean isHasNetwork() {
		return hasNetwork;
	}
	public void setHasNetwork(boolean hasNetwork) {
		this.hasNetwork = hasNetwork;
	}
	public boolean isHasNode() {
		return hasNode;
	}
	public void setHasNode(boolean hasNode) {
		this.hasNode = hasNode;
	}
	public String getParamName() {
		return paramName;
	}
	public void setParamName(String paramName) {
		this.paramName = paramName;
	}
	public Map<String, Object> getMapping() {
		return mapping;
	}
	public void setMapping(Map<String, Object> mapping) {
		this.mapping = mapping;
	}
	public Object[] getParams() {
		return params;
	}
	public void setParams(Object[] params) {
		this.params = params;
	}
	
	
}
