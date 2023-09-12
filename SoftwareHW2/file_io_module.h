#ifndef FILE_IO_MODULE
#define FILE_IO_MODULE

#include <string>

// 获取指定路径的文本
//  - path 文件路径
//  - return 文件的字符串
std::string load_text(std::string& path);

// 将结果写入指定的文件
//  - path 文件路径
//  - similarity 写入的结果
void write_answer(std::string& path, double similarity);

#endif // !FILE_IO_MODULE
