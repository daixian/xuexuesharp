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
        public void Test1()
        {
            //只会搜索目录下的文件
            string[] files = Directory.GetFiles("C:/");

            Assert.Pass();
        }
    }
}