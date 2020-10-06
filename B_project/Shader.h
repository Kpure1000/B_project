#pragma once
#include<glad/glad.h>
#include<GLFW/glfw3.h>
#include<string>
#include<iostream>
#include<fstream>
using namespace std;

// TYPE OF SHADER
enum class ShaderType
{
	VERT, // VERTEX
	GEOM, // GEOMETRY
	FRAG  // FRAGMENT
};
// CLASS OF SHADER
class Shader
{
public:
	/// <summary>
	/// construct by string of shader code
	/// </summary>
	/// <param name="shaderStr"></param>
	/// <param name="shaderType"></param>
	Shader(string shaderStr, ShaderType shaderType)
	{
		shaderProgram = glCreateProgram();
		ShaderCodeSwitcher(shaderStr, shaderType);
	}
	/// <summary>
	/// construct by file of shader(s). 
	/// If file is not exist, set file name as "".
	/// </summary>
	/// <param name="vertexShaderFileName">.vert shader</param>
	/// <param name="geometryShaderFileName">.geom shader</param>
	/// <param name="fragmentShaderFileName">.frag shader</param>
	Shader(string const& vertexShaderFileName, string const& geometryShaderFileName, string const& fragmentShaderFileName)
	{
		shaderProgram = glCreateProgram();
		if (vertexShaderFileName != "")
		{
			string code;
			ReadCodeByLine(code, vertexShaderFileName);
			ShaderCodeSwitcher(code, ShaderType::VERT);
		}
		if (geometryShaderFileName != "")
		{
			string code;
			ReadCodeByLine(code, geometryShaderFileName);
			ShaderCodeSwitcher(code, ShaderType::GEOM);

		}
		if (fragmentShaderFileName != "")
		{
			string code;
			ReadCodeByLine(code, fragmentShaderFileName);
			ShaderCodeSwitcher(code, ShaderType::FRAG);
		}
	}

	void Use()
	{
		glLinkProgram(shaderProgram);
		GLint success;
		char infoLog[512];
		glGetProgramiv(shaderProgram, GL_LINK_STATUS, &success);
		if (!success) {
			glGetProgramInfoLog(shaderProgram, 512, NULL, infoLog);
			//Shader Link Error 
			cout << "Shader program link failed with exception: \n" << infoLog << endl;
		}
		else
		{
			glUseProgram(shaderProgram);
			vertexShaderID == -1 ? NULL : NULL, glDeleteShader(vertexShaderID);
			geometryShaderID == -1 ? NULL : NULL, glDeleteShader(geometryShaderID);
			fragmentShaderID == -1 ? NULL : NULL, glDeleteShader(fragmentShaderID);
		}
	}

private:
	/* PRIVATE METHOD */

	/// <summary>
	/// switch shader code to compile by shader type
	/// </summary>
	/// <param name="shaderStr">shader code string</param>
	/// <param name="shaderType">shader type</param>
	void ShaderCodeSwitcher(string const& shaderStr, ShaderType shaderType)
	{
		switch (shaderType)
		{
		case ShaderType::VERT:
			CompileShader(vertexShaderID, shaderStr, GL_VERTEX_SHADER);
			break;
		case ShaderType::GEOM:
			CompileShader(geometryShaderID, shaderStr, GL_GEOMETRY_SHADER);
			break;
		case ShaderType::FRAG:
			CompileShader(fragmentShaderID, shaderStr, GL_FRAGMENT_SHADER);
			break;
		default:
			break;
		}
	}

	/// <summary>
	/// Compile shader code with error info
	/// </summary>
	/// <param name="shaderID">shader id</param>
	/// <param name="shaderCode">shader string code</param>
	/// <param name="shaderType">shader type</param>
	void CompileShader(GLuint& shaderID, string shaderCode, GLenum shaderType)
	{
		GLchar* shaderCh = (GLchar*)shaderCode.c_str();
		shaderID = glCreateShader(shaderType);
		glShaderSource(shaderID, 1, &shaderCh, NULL);
		glCompileShader(shaderID);
		int success;
		char infoLog[1024];
		glGetShaderiv(shaderID, GL_COMPILE_STATUS, &success);
		if (!success)
		{
			glGetShaderInfoLog(shaderID, 1024, NULL, infoLog);
			//Shader Compile Error
			std::cout << "Shader code compile failed with exception: \n" << infoLog << std::endl;
		}
		else
		{
			glAttachShader(shaderProgram, shaderID);
		}
	}

	/// <summary>
	/// read text file by each line
	/// </summary>
	/// <param name="codeOut"></param>
	/// <param name="fileName"></param>
	void ReadCodeByLine(string& codeOut, string const& fileName)
	{
		ifstream infile(fileName);
		char strBuffer[255] = "";
		string shaderCode;
		bool eof = false;
		if (infile.is_open())
		{
			while (!eof)
			{
				eof = infile.getline(strBuffer, 255).eof();
				shaderCode += strBuffer;
				shaderCode += '\n';
			}
			//cout <<"Shader file '"<<fileName<< "', with Code: \n" << shaderCode << endl;
		}
	}

private:
	/// <summary>
	/// vertex shader object id
	/// </summary>
	GLuint vertexShaderID = -1;
	/// <summary>
	/// geometry shader object id
	/// </summary>
	GLuint geometryShaderID = -1;
	/// <summary>
	/// fragment shader object id
	/// </summary>
	GLuint fragmentShaderID = -1;

	/// <summary>
	/// shader program object
	/// </summary>
	GLuint shaderProgram = -1;
};

