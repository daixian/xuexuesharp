# xuexuesharp :snowflake:

这是C++实现的一些仿C#类库的常用接口，主要补全一下Poco库中没有的。目前是一些文件读写操作和字符串编码的转换等等，会逐渐的增加一些方法进来。

## File
File类在C#中是静态类，这里实现了一些相似的方法。

``` cpp
#include "xuexue/csharp/File.h"

using namespace std;
using namespace xuexue::csharp;

string text = "111\r\n222\r\n333\n";
File::WriteAllText("FileTest.txt", text);
string text2 = File::ReadAllText("FileTest.txt");
File::Delete("FileTest.txt");
```