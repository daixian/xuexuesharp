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


            p = Path.Combine("1", "/2/3/");
            Assert.AreEqual(p, "/2/3/");

            p = Path.Combine("/1", "/2/3/");
            Assert.AreEqual(p, "/2/3/");

            p = Path.Combine("/1/", "/2/3/");
            Assert.AreEqual(p, "/2/3/");

            p = Path.Combine("/1", "\\2/3/");
            Assert.AreEqual(p, "\\2/3/");


            p = Path.Combine("1", "2/3/");
            Assert.AreEqual(p, "1\\2/3/");


            Assert.AreEqual(File.Exists("./"), false);
            Assert.AreEqual(File.Exists("."), false);
            bool res = File.Exists(".");
        }

        [Test]
        public void Test2()
        {
            Assert.AreEqual(Path.IsPathFullyQualified("1123"), false);
            Assert.AreEqual(Path.IsPathFullyQualified("/1123"), false);
            Assert.AreEqual(Path.IsPathFullyQualified("\\"), false);
            Assert.AreEqual(Path.IsPathFullyQualified("C:/1123"), true);
            Assert.AreEqual(Path.IsPathFullyQualified("C:/"), true);
            Assert.AreEqual(Path.IsPathFullyQualified("G:/"), true);

            Assert.AreEqual(Path.IsPathRooted("1123"), false);
            Assert.AreEqual(Path.IsPathRooted("/1123"), true);
            Assert.AreEqual(Path.IsPathRooted("\\1123"), true);
            Assert.AreEqual(Path.IsPathRooted("C:/1123"), true);

        }
    }
}
