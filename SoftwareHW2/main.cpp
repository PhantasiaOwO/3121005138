#include "file_io_module.h"
#include "similarity_detection.h"
#include "cppjieba/Jieba.hpp"

using namespace std;

const string JIEBA_DICT_PATH = "";
const string JIEBA_MODEL_PATH = "";
const string JIEBA_USER_DICT_PATH = "";
const string JIEBA_IDF_PATH = "";
const string JIEBA_STOP_WORD_PATH = "";

int main(int argc, char* argv[]) {
    // handle shell parameters
    if(argc < 3) return 0;
    string origin_path = string(argv[0]);
    string target_path = string(argv[1]);
    string answer_path = string(argv[2]);
        
    cppjieba::Jieba jb(JIEBA_DICT_PATH, JIEBA_MODEL_PATH, JIEBA_USER_DICT_PATH, JIEBA_IDF_PATH, JIEBA_STOP_WORD_PATH);
    SimilarityDetection sd(jb);
    string origin = load_text(origin_path);
    string target = load_text(target_path);
    sd.set_two_strings(origin, target);
    double ret = sd.get_similarity();
    write_answer(answer_path, ret);
    return 0;
}
