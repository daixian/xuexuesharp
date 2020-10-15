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
        }

        [Test]
        public void TestGetDirectoryRoot()
        {
            string root = Directory.GetDirectoryRoot("./");
            //在mac下这个root是返回/
        }

        [Test]
        public void TestGetDirectories()
        {
            string[] dirs = Directory.GetDirectories("./");
            //在mac下这个root是返回/
        }
    }
}