#ifndef SIMILARITY_DETECTION
#define SIMILARITY_DETECTION

#include <codecvt>
#include <vector>
#include <cvt/wstring>

#include "cppjieba/Jieba.hpp"

class SimilarityDetection {
private:
    // 分词库实例
    cppjieba::Jieba jieba_;
    // 转换器，用于中文宽字符和utf8之间转换
    stdext::cvt::wstring_convert<std::codecvt_utf8<wchar_t>> cvt_;
    // 原文
    std::string origin_;
    // 目标文章
    std::string target_;
    // 相似度
    double similarity_ = -1;

    // 余弦相似度算法本体
    //  - origin 原文字符串
    //  - target 目标字符串
    double cosine_similarity(const std::vector<std::string>& origin, const std::vector<std::string>& target);

    // 字符串预处理
    //  - origin 原文字符串
    //  - return 处理之后的字符串
    std::vector<std::vector<std::string>> preprocess_string(const std::string& origin);
public:
    SimilarityDetection(cppjieba::Jieba& jieba) : jieba_(jieba) { }

    // 设置两个字符串
    //  - origin 原文字符串
    //  - target 目标字符串
    void set_two_strings(const std::string& origin, const std::string& target);

    // 获取原文相似度
    double get_similarity();
};

#endif  // !SIMILARITY_DETECTION
