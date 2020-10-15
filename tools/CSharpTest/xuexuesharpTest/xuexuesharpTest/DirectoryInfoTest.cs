using NUnit.Framework;
using System;
using System.IO;

namespace xuexuesharpTest
{
    public class DirectoryInfoTest
    {
        [SetUp]
        public void Setup()
        {
        }

        [Test]
        public void TestDirectoryInfo()
        {
            DirectoryInfo di = new DirectoryInfo("./");
            DirectoryInfo di2 = new DirectoryInfo(".");

            // ./的末尾会带上/但是.的末尾不会带上
            Assert.AreEqual(di.FullName, di2.FullName + Path.DirectorySeparatorChar);

        }


        [Test]
        public void TestGetDirectories()
        {
            DirectoryInfo di2 = new DirectoryInfo(".");
            DirectoryInfo[] dirs = di2.GetDirectories();


            //在mac下这个root是返回/
        }



    }
}