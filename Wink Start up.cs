using System;
using System.Collection.Generic;
using System.Text;
using Sys = Cosmos.System;

namespace Wink_OS

{
    public class Kernel : Sys.Kernel
    {
        protected override void BeforeRun()
        {
            Console.WriteLine("Wink is booted successfully.")
        }

        protected override void Run()
        {
            Console.WriteLine("One");
             Console.WriteLine("Two");
              Console.WriteLine("Three");
        }
    }
}