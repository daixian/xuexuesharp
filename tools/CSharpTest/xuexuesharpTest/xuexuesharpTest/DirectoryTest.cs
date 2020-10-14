using NUnit.Framework;
using System.IO;

namespace xuexuesharpTest
{
    public class DirectoryTest
    {
        [SetUp]
        public void Setup()
        {
        }

        [Test]
        public void TestGetFiles()
        {
            //只会搜索目录下的文件
            string[] files = Directory.GetFiles("./");

            //Assert.Pass();
            string root = Directory.GetDirectoryRoot("./");
        }

        
        [Test]
        public void TestGetFiles()
        {
            string root = Directory.GetDirectoryRoot("./");
            //在mac下这个root是返回/
        }
    }
}