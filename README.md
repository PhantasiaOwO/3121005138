# 软工作业2：C++实现简易论文查重

## 需求分析和详细设计

### 文件输入输出模块

需要实现如下功能

- 文件内容读取并将文本存入内存（函数）
- 将数据结果写入答案文件（函数）



程序以命令行参数启动

```shell
main.exe [原文文件] [抄袭版论文的文件] [答案文件]
```

原文文件和抄袭版论文文件使用读取功能，获取数据；答案文件使用写入功能

### 查重类设计

#### 数据处理模块

对文本内容进行预处理（函数），有如下的步骤

- 按段落分割文本
- 去除文本中的标点符号
- 对文本进行分词

文本分词使用库 [Github: cppjieba](https://github.com/yanyiwu/cppjieba/tree/master)

#### 查重模块

使用的查重算法为 **余弦相似度算法**

文本经过文本处理模块后，将会存储为二维向量，第一维为段落，第二维为该段落的分词结果

对两段文本的分词结果使用余弦相似度算法，得到每一个段落之间的余弦相似度

对所有的相似度结果取平均，即为文本最终的重复率

## 代码规范

### 文件命名

只允许出现小写字符

- `example_class.cpp`
- `example_class.h`

### 函数与变量命名

| Type                     | Naming           |
| ------------------------ | ---------------- |
| Function                 | `all_lower`      |
| Variable                 | `all_lower`      |
| Constant                 | `ALL_UPPER`      |
| Macro                    | `ALL_UPPER`      |
| Class/Struct name        | `UpperCamelCase` |
| Class/Struct data member | `all_lower_`     |

### 注释

使用 `//` 进行注释

#### 函数内注释

注释的位置仅允许在关键代码前一行或者关键代码后

```C++
void foo() {
    foo1(); // This is a comment
    
    // This is a comment
    foo2();
}
```

#### 函数定义注释

函数定义的注释需要说明函数的用途，需要详细描述参数和返回值

```C++
// Get the sign of number
//	- f the number you want to get
//	- return sign of the number. positive or zero return 1, negative return -1
float sign(float f) { }
```

#### 变量声明注释

说明变量的含义和使用

```C++
float torque; // The torque of the engine

// The torque from break comp
float brake_torque;
```

