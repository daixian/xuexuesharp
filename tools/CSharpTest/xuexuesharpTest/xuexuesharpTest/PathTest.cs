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

        [Test]
        public void TestGetDirectoryName()
        {
            Assert.AreEqual(Path.GetDirectoryName(@"C:\MyDir\MySubDir\myfile.ext"), @"C:\MyDir\MySubDir");
            Assert.AreEqual(Path.GetDirectoryName(@"C:\MyDir\MySubDir"), @"C:\MyDir");
            Assert.AreEqual(Path.GetDirectoryName(@"C:\MyDir\"), @"C:\MyDir");
            Assert.AreEqual(Path.GetDirectoryName(@"C:\MyDir"), @"C:\");
            Assert.AreEqual(Path.GetDirectoryName(@"C:\"), null);

            Assert.AreEqual(Path.GetDirectoryName(@"1\2\3"), @"1\2");
            Assert.AreEqual(Path.GetDirectoryName(@"/"), null);
            Assert.AreEqual(Path.GetDirectoryName(@"\\"), null);

            Assert.AreEqual(Path.GetDirectoryName(@"123"), "");
        }

        [Test]
        public void TestGetExtension()
        {
            Assert.AreEqual(Path.GetExtension(@"C:\MyDir\MySubDir\myfile.ext"), ".ext");
            Assert.AreEqual(Path.GetExtension(@"C:\MyDir\"), "");
            Assert.AreEqual(Path.GetExtension(@"C:\MyDir\123"), "");
        }
    }
}
