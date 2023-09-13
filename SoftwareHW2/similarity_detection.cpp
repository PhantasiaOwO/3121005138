#include "similarity_detection.h"

#include <map>
#include <string>

using namespace std;

double SimilarityDetection::cosine_similarity(const vector<string>& split_origin, const vector<string>& split_target) {
    map<string, pair<int, int>> word_vector;
    for (const string& s : split_origin) ++word_vector[s].first;
    for (const string& s : split_target) ++word_vector[s].second;

    double sum_multiply = 0;
    double sum_origin_sq = 0;
    double sum_target_sq = 0;
    for (const pair<const string, pair<int, int>>& pair : word_vector) {
        const double v1 = pair.second.first;
        const double v2 = pair.second.second;
        sum_multiply += v1 * v2;
        sum_origin_sq += v1 * v1;
        sum_target_sq += v2 * v2;
    }
    const double cosine = sum_multiply / ::sqrt(sum_origin_sq) / ::sqrt(sum_target_sq);
    return cosine;
}

vector<string> SimilarityDetection::preprocess_string(const string& origin) {
    const wstring ws = cvt_->from_bytes(origin);
    wstring preprocess;
    vector<string> ret;
    for (const wchar_t ch : ws) {
        // char culling
        if (iswpunct(ch) || iswspace(ch)) continue;
        if (ch == L'，' || ch == L'。' || ch == L'？' || ch == L'：'
            || ch == L'！' || ch == L'“' || ch == L'”' || ch == L'、'
            || ch == L'；')
            continue;
        preprocess.push_back(ch);
    }
    jieba_->Cut(cvt_->to_bytes(preprocess), ret);
    return ret;
}

void SimilarityDetection::set_two_strings(const string& origin, const string& target) {
    origin_ = origin;
    target_ = target;
    similarity_ = -1;
}

double SimilarityDetection::get_similarity() {
    if (similarity_ > -0.5) return similarity_;
    vector<string> origin_preprocessed = preprocess_string(origin_);
    vector<string> target_preprocessed = preprocess_string(target_);
    return cosine_similarity(origin_preprocessed, target_preprocessed);
}
