#include "pch.h"
#include "CppUnitTest.h"

#include "../SoftwareHW2/similarity_detection.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;
using namespace std;

namespace CalculateUnitTest
{
	TEST_CLASS(CalculateUnitTest)
	{
	public:

		TEST_METHOD(TestMethod1)
		{
			const string JIEBA_DICT_PATH = "E:/projects/SoftwareHW2/CalculateUnitTest/dict/jieba.dict.utf8";
			const string JIEBA_MODEL_PATH = "E:/projects/SoftwareHW2/CalculateUnitTest//dict/hmm_model.utf8";
			const string JIEBA_USER_DICT_PATH = "E:/projects/SoftwareHW2/CalculateUnitTest//dict/user.dict.utf8";
			const string JIEBA_IDF_PATH = "E:/projects/SoftwareHW2/CalculateUnitTest//dict/idf.utf8";
			const string JIEBA_STOP_WORD_PATH = "E:/projects/SoftwareHW2/CalculateUnitTest//dict/stop_words.utf8";

			cppjieba::Jieba jb(JIEBA_DICT_PATH, JIEBA_MODEL_PATH, JIEBA_USER_DICT_PATH, JIEBA_IDF_PATH, JIEBA_STOP_WORD_PATH);
			wstring_convert<codecvt_utf8<wchar_t>> cvt;
			SimilarityDetection sd(&jb, &cvt);

			string s1 = string(cvt.to_bytes(L"���������ܺã�̫���������"));
			string s2 = string(cvt.to_bytes(L"�����������ʣ�̫���ܴ�"));

			sd.set_two_strings(s1, s2);
			double data = sd.get_similarity();
			// Assert::AreSame(data, 4.0 / 6 / 6);
		}

		TEST_METHOD(TestMethod2)
		{
			const string JIEBA_DICT_PATH = "E:/projects/SoftwareHW2/CalculateUnitTest/dict/jieba.dict.utf8";
			const string JIEBA_MODEL_PATH = "E:/projects/SoftwareHW2/CalculateUnitTest//dict/hmm_model.utf8";
			const string JIEBA_USER_DICT_PATH = "E:/projects/SoftwareHW2/CalculateUnitTest//dict/user.dict.utf8";
			const string JIEBA_IDF_PATH = "E:/projects/SoftwareHW2/CalculateUnitTest//dict/idf.utf8";
			const string JIEBA_STOP_WORD_PATH = "E:/projects/SoftwareHW2/CalculateUnitTest//dict/stop_words.utf8";

			cppjieba::Jieba jb(JIEBA_DICT_PATH, JIEBA_MODEL_PATH, JIEBA_USER_DICT_PATH, JIEBA_IDF_PATH, JIEBA_STOP_WORD_PATH);
			wstring_convert<codecvt_utf8<wchar_t>> cvt;
			SimilarityDetection sd(&jb, &cvt);

			string s1 = string(cvt.to_bytes(L"�����������죬�����磬����������Ҫȥ����Ӱ��"));
			string s2 = string(cvt.to_bytes(L"���������죬�������ʣ�������Ҫȥ����Ӱ��"));

			sd.set_two_strings(s1, s2);
			double data = sd.get_similarity();
			// Assert::AreSame(data, 4.0 / 6 / 6);
		}

		TEST_METHOD(TestMethod3)
		{
			const string JIEBA_DICT_PATH = "E:/projects/SoftwareHW2/CalculateUnitTest/dict/jieba.dict.utf8";
			const string JIEBA_MODEL_PATH = "E:/projects/SoftwareHW2/CalculateUnitTest//dict/hmm_model.utf8";
			const string JIEBA_USER_DICT_PATH = "E:/projects/SoftwareHW2/CalculateUnitTest//dict/user.dict.utf8";
			const string JIEBA_IDF_PATH = "E:/projects/SoftwareHW2/CalculateUnitTest//dict/idf.utf8";
			const string JIEBA_STOP_WORD_PATH = "E:/projects/SoftwareHW2/CalculateUnitTest//dict/stop_words.utf8";

			cppjieba::Jieba jb(JIEBA_DICT_PATH, JIEBA_MODEL_PATH, JIEBA_USER_DICT_PATH, JIEBA_IDF_PATH, JIEBA_STOP_WORD_PATH);
			wstring_convert<codecvt_utf8<wchar_t>> cvt;
			SimilarityDetection sd(&jb, &cvt);

			string s1 = string(cvt.to_bytes(L"����Ҫ�����֮��Ϧ�ദ����ʵ����������е����Գ��ܣ���ӵ��������ʵ����������˵�ų������գ��־͹������Ϊʲô����������������ߣ������õ�����ȴԶ�ں��ǡ����仰˵���˵��Ѱ���ͬ������ֻ����Ϊ�������������෴����ʵ�������ֱ�ɴ���������һλʫ�������ģ������޷�����̫�����ʵ��Ҳ�����������ң�һ�����ڽ�����Һ���ʵ�Ľ��Ź�ϵ������������Ϊ�ɹ������ӣ����ҵ���һ���º͵�;��������д�м�״̬�����ͬʱ�����������������������Ϸ�����ʵ�ŵ�����ʷ�����ľ���֮�У��������������ϵ���ѧ��ʵ����Ϊ�������Ź�ȥ�ͽ�����"));
			string s2 = string(cvt.to_bytes(L"���̼�Ҫ�����֮�޳�Ϧ�ദ����ʵ������������е����Գ��ܣ�����ӵ�϶���������ʵ������������˵�ų������գ��ع��¾ͷ��������Ϊʲô����������˱�������۱ߣ��������õ�������ȴԶ�ں��ǡ��������˵���˻���Ѱ���ͬ������ֻ����Ϊ�������������෴����ʵ�����������ֱ���ɴ��輰������һλʫ�˼������ģ������޷�������̫���������ӿʵ��Ҳ�����������ң���һ�������ڿ�������ʰ����ʵ�εĽ��Źؿ�ϵ������������Ϊ�ɹ��������ӣ����ҵ�����һ�����������;����������д�м�ײ״̬����į�ͬʱ�����������������ȼ�������Ϸ�������ʵ�ŵ�����ʷ�������ľ���֮�У���������������ϵ��Ľ�ѧ��ʵ����Ϊ�������Ź�ȥ���ͽ�����"));

			sd.set_two_strings(s1, s2);
			double data = sd.get_similarity();
			// Assert::AreSame(data, 4.0 / 6 / 6);
		}
	};
}
