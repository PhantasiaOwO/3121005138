﻿#include "similarity_detection.h"

#include <map>
#include <string>

using namespace std;

double SimilarityDetection::cosine_similarity(const string& origin, const string& target) {}

vector<string> SimilarityDetection::preprocess_string(const string& origin) {
    const wstring ws = cvt_.from_bytes(origin);
    vector<string> ret;
    wstring preprocess;
    for (const wchar_t ch : ws) {
        if (iswpunct(ch) || iswspace(ch)) continue;
        if (ch == L'，' || ch == L'。' || ch == L'？' || ch == L'：'
            || ch == L'！' || ch == L'“' || ch == L'”' || ch == L'、'
            || ch == L'；')
            continue;
        preprocess.push_back(ch);
        if (ch != L'\n') continue;
        preprocess.push_back(L'\0');
        ret.push_back(cvt_.to_bytes(preprocess));
        preprocess.clear();
    }
    return ret;
}

void SimilarityDetection::set_two_strings(const string& origin, const string& target) {
    origin_ = origin;
    target_ = target;
}

double SimilarityDetection::get_similarity() {}
