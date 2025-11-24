#include "pch.h"
#include "CppUnitTest.h"
#include "C:\Users\Family\Desktop\Оптіма Максим\ХПІ\Software engeneering\SE_PROGRAM_REAL\SE_PROGRAM_REAL\InputN.h"
#include "C:\Users\Family\Desktop\Оптіма Максим\ХПІ\Software engeneering\SE_PROGRAM_REAL\SE_PROGRAM_REAL\InputPositiveStep.h"
#include "C:\Users\Family\Desktop\Оптіма Максим\ХПІ\Software engeneering\SE_PROGRAM_REAL\SE_PROGRAM_REAL\InputNegativeStep.h"
#include "C:\Users\Family\Desktop\Оптіма Максим\ХПІ\Software engeneering\SE_PROGRAM_REAL\SE_PROGRAM_REAL\Calculator.h"
using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTEST
{
    TEST_CLASS(InputNTests) {
public:
    TEST_METHOD(TestDoubleN_for_N) {
        double test_val = 3.6;
        Assert::ExpectException<std::invalid_argument>([&]() { ValidateN(test_val); }, L"Test failed for n = 3.6");
    }
    TEST_METHOD(TestOneN_for_N) {
        double test_val = 1;
        Assert::ExpectException<std::invalid_argument>([&]() { ValidateN(test_val); }, L"Test failed for n = 1.");
    }
    TEST_METHOD(TestNegativeN_for_N) {
        double test_val = -1;
        Assert::ExpectException<std::invalid_argument>([&]() { ValidateN(test_val); }, L"Test failed for n = 0");
    }
    TEST_METHOD(TestPositiveBetterThenOneN_for_N) {
        double test_val = 36.0;
        int expected = 36;
        int actual = ValidateN(test_val);
        Assert::AreEqual(expected, actual, L"Test failed for n = 36");
    }
    };

    TEST_CLASS(InputStepTests) {
public:
    TEST_METHOD(TestInputPositiveStep_for_PositiveStep) {
        double step = 2.5;
        double expectedStep = 2.5;
        double actualStep = ValidatenPositiveStep(step);
        Assert::AreEqual(expectedStep, actualStep, L"Test failed for step 2.5 in PositiveStep");
    }
    TEST_METHOD(TestInputNegativeStep_for_PositiveStep) {
        double step = -2.5;
        Assert::ExpectException<std::invalid_argument>([&]() { ValidatenPositiveStep(step); }, L"Test failed for step -2.5 in PositiveStep");
    }
    TEST_METHOD(TestZeroStep_for_PositiveStep) {
        double step = 0;
        Assert::ExpectException<std::invalid_argument>([&]() { ValidatenPositiveStep(step); }, L"Test failed for step 0 in PositiveStep");
    }

    TEST_METHOD(TestInputPositiveStep_for_NegativeStep) {
        double step = 2.5;
        Assert::ExpectException<std::invalid_argument>([&]() { ValidatenNegativeStep(step); }, L"Test failed for step 2.5 in NegativeStep");
    }
    TEST_METHOD(TestInputNegativeStep_for_NegativeStep) {
        double step = -2.5;
        double expectedStep = -2.5;
        double actualStep = ValidatenNegativeStep(step);
        Assert::AreEqual(expectedStep, actualStep, L"Test failed for step -2.5 in NegativeStep");
    }
    TEST_METHOD(TestZeroStep_for_NegativeStep) {
        double step = 0;
        Assert::ExpectException<std::invalid_argument>([&]() { ValidatenNegativeStep(step); }, L"Test failed for step 0 in NegativeStep");
    }
    };

    TEST_CLASS(ClaculationsTests) {
        TEST_METHOD(TestPositiveX) {
            double x = 2.5;
            int n = 4;
            double expectedRes = 3408885.432415369;
            double actualRes = Calculator(x, n);
            Assert::AreEqual(expectedRes, actualRes, 0.0001, L"Test failed for x = 2.5");
        }

        TEST_METHOD(TestNegativeX) {
            double x = -10;
            int n = 2;
            double expectedRes = -30.4848;
            double actualRes = Calculator(x, n);
            Assert::AreEqual(expectedRes, actualRes, 0.0001, L"Test failed for x = -2.5");
        }

        TEST_METHOD(TestZeroX) {
            double x = 0;
            int n = 2;
            double expectedRes = 4.5;
            double actualRes = Calculator(x, n);
            Assert::AreEqual(expectedRes, actualRes, 0.0001, L"Test failed for x = 0");
        }
    };
}
