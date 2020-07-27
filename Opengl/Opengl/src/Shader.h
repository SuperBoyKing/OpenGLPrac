#pragma once
#ifndef SHADER_H
#define SHADER_H

#include <string>

struct ShaderProgramSource
{
	std::string VertexSource;
	std::string FragmentSource;
};

class Shader
{
private:
	std::string m_FilePath;

public:
	unsigned int m_ProgramID;
	Shader(const std::string& filePath);
	~Shader();

	void Bind() const;
	void UnBind() const;

	void setBool(const std::string& name, bool value) const;
	void setInt1f(const std::string& name, int value) const;
	void setFloat1f(const std::string& name, float value) const;

private:
	ShaderProgramSource ParseShader(const std::string& filePath);
	unsigned int CompileShader(unsigned int type, const std::string& source);
	unsigned int CreateShader(const std::string& vertexShader, const std::string& fragmentShader);
};

#endif SHADER_H