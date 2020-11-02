using NUnit.Framework;
using System;
using System.Collections.Generic;
using System.IO;
using System.Text;

namespace xuexuesharpTest
{
    class PathTest
    {
        [SetUp]
        public void Setup()
        {
        }

        [Test]
        public void Test()
        {
            string p = Path.Combine("1", "2");
            Assert.AreEqual(p, "1\\2");

            Assert.AreEqual(File.Exists("./"), false);
            Assert.AreEqual(File.Exists("."), false);
            bool res = File.Exists(".");
        }
    }
}
