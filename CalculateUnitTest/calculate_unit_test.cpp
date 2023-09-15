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

			string s1 = string(cvt.to_bytes(L"今天天气很好，太阳很舒服。"));
			string s2 = string(cvt.to_bytes(L"今天天气晴朗，太阳很大。"));

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

			string s1 = string(cvt.to_bytes(L"今天是星期天，天气晴，今天晚上我要去看电影。"));
			string s2 = string(cvt.to_bytes(L"今天是周天，天气晴朗，我晚上要去看电影。"));

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

			string s1 = string(cvt.to_bytes(L"作家要表达与之朝夕相处的现实，他常常会感到难以承受，蜂拥而来的真实几乎都在诉说着丑恶和阴险，怪就怪在这里，为什么丑恶的事物总是在身边，而美好的事物却远在海角。换句话说，人的友爱和同情往往只是作为情绪来到，而相反的事实则是伸手便可触及。正像一位诗人所表达的：人类无法忍受太多的真实。也有这样的作家，一生都在解决自我和现实的紧张关系，福克纳是最为成功的例子，他找到了一条温和的途径，他描写中间状态的事物，同时包容了美好与丑恶，他将美国南方的现实放到了历史和人文精神之中，这是真正意义上的文学现实，因为它连接着过去和将来。"));
			string s2 = string(cvt.to_bytes(L"作禾家要表达与之赊朝夕相处的现实，袄他常常会感到难以承受，径蜂拥氏而来的殃真实几乎数都在诉说着丑恶和阴险，截怪陕就坊怪在这里，为什么丑恶的事物总吮是在身袍边，而美唉好的事帕物却远在海角。换句疙话滥说，人烩的友爱和同情往往只是作为情绪来到，而相反的事实则助是诅伸手便象可触借及。正像一位诗人茧所表达的：人类无法唾忍受太尹多的奄真涌实。也有这样的作家，杨一生都掺在款解决自我拾和现实瘴的紧张关棵系，福克纳是最为成功幅的例子，他找到吃了一条温落和屏的途径，他镭描写中间撞状态的事寞物，同时署包容了美好与丑恶，他燃将美国南方的乃现实放到了历史和人球文精神之中，这贯是真正意义上的文浆学现实，因为它连接着过去琐和将来。"));

			sd.set_two_strings(s1, s2);
			double data = sd.get_similarity();
			// Assert::AreSame(data, 4.0 / 6 / 6);
		}
	};
}
