#! /bin/bash

conan create . daixian/stable -s build_type=Release --build missing
# conan create . daixian/stable --profile=NDK --build missing