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
            //ֻ������Ŀ¼�µ��ļ�
            string[] files = Directory.GetFiles("C:/");

            Assert.Pass();
        }
    }
}