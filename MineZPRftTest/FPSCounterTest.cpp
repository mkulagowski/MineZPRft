/**
 * @file
 * @author mkkulagowski (mkkulagowski(at)gmail.com)
 * @brief  FPS counter class tests
 */

#include <gtest/gtest.h>
#include "Common/FPSCounter.hpp"
#include <chrono>
#include <thread>
#include <iostream>

#define FRAME_TIME 16

TEST(FPSCounter, Constructor)
{
    FPSCounter a;

    // All counters are 0 and default period is 5 seconds.
    ASSERT_EQ(0.0f, a.GetAvgFrameCount());
    ASSERT_EQ(0.0f, a.GetPeriodFrameCount());
    ASSERT_EQ(5, a.GetPeriod());
}

TEST(FPSCounter, ConstructorSingleInt)
{
    // Create with period = 10s.
    FPSCounter a(10);

    // All counters are 0 and default period should be 10 seconds.
    ASSERT_EQ(0.0f, a.GetAvgFrameCount());
    ASSERT_EQ(0.0f, a.GetPeriodFrameCount());
    ASSERT_EQ(10, a.GetPeriod());
}

TEST(FPSCounter, SetPeriod)
{
    // Create with period = 10s.
    FPSCounter a(10);

    // Default period should be 10 seconds.
    ASSERT_EQ(10, a.GetPeriod());

    a.SetPeriod(15);
    // All counters are 0 and default period should be 10 seconds.
    ASSERT_EQ(0.0f, a.GetAvgFrameCount());
    ASSERT_EQ(0.0f, a.GetPeriodFrameCount());
    ASSERT_EQ(15, a.GetPeriod());
}

TEST(FPSCounter, PreAverageCount)
{
    // Create and start objects.
    FPSCounter a; ///< Note: FPSCounter's clock starts with object creation.

    for (int i = 0; i < 100; ++i)
    {
        // This method should give value only after first 100 calls
        ASSERT_EQ(a.GetAvgFrameCount(), 0);

        // Wait single frame.
        std::this_thread::sleep_for(std::chrono::milliseconds(FRAME_TIME / 4));

        // Sum elapsed time, restart timers, increment counters.
        // Note: For FPSCounter all is done within Run() method.
        a.Run();
    }

    // Avg FPS should now return some value
    ASSERT_GT(a.GetAvgFrameCount(), 0);
}

TEST(FPSCounter, AverageCount)
{
    // Create and start objects.
    double time = 0;
    int counter = 0;
    Timer timer;

    FPSCounter a; ///< Note: FPSCounter's clock starts with object creation.
    timer.Start();
    for (int i = 0; i < 100; ++i)
    {
        // Wait single frame.
        std::this_thread::sleep_for(std::chrono::milliseconds(FRAME_TIME / 4));

        // Sum elapsed time, restart timers, increment counters.
        // Note: For FPSCounter all is done within Run() method.
        time += timer.Stop();
        timer.Start();
        a.Run();
        counter++;
    }

    float fps = static_cast<float>(counter / time);

    // Avg FPS should be approx. the same as calculated one.
    ASSERT_LE(fps - a.GetAvgFrameCount(), 0.5);
    ASSERT_GE(fps - a.GetAvgFrameCount(), -0.5);
}

TEST(FPSCounter, StandardPeriodCount)
{
    // Create and start objects.
    double time = 0;
    int counter = 0;
    Timer timer;

    timer.Start();
    FPSCounter a;

    // Run objects in a 5s loop, so the period FPS gets calculated.
    do
    {
        // Wait single frame.
        std::this_thread::sleep_for(std::chrono::milliseconds(FRAME_TIME));

        // Sum elapsed time, restart timers, increment counters.
        // Note: For FPSCounter all is done within Run() method.
        time += timer.Stop();
        timer.Start();
        a.Run();
        counter++;
    } while (time <= 5);

    // Calculate/Get fps values.
    float fps = static_cast<float>(counter / time);
    float counterFPS = a.GetPeriodFrameCount();

    // Period FPS gets cleared upon calling Get*() method.
    ASSERT_EQ(a.GetPeriodFrameCount(), 0.0);

    // Period FPS should be approx. the same as calculated one.
    ASSERT_LE(fps - counterFPS, 0.5);
    ASSERT_GE(fps - counterFPS, -0.5);
}

TEST(FPSCounter, CustomPeriodCount)
{
    // Create and start objects.
    double time = 0;
    int counter = 0;
    Timer timer;

    timer.Start();
    FPSCounter a(3);

    // Run objects in a 3s loop, so the period FPS gets calculated.
    do
    {
        // Wait single frame.
        std::this_thread::sleep_for(std::chrono::milliseconds(FRAME_TIME));

        // Sum elapsed time, restart timers, increment counters.
        // Note: For FPSCounter all is done within Run() method.
        time += timer.Stop();
        timer.Start();
        a.Run();
        counter++;
    } while (time <= 3);

    // Calculate/Get fps values.
    float fps = static_cast<float>(counter / time);
    float counterFPS = a.GetPeriodFrameCount();

    // Period FPS should be approx. the same as calculated one.
    ASSERT_LE(fps - counterFPS, 0.5);
    ASSERT_GE(fps - counterFPS, -0.5);
}

TEST(FPSCounter, CustomPeriodPreCount)
{
    // Create and start objects.
    double time = 0;
    Timer timer;

    timer.Start();
    FPSCounter a(10);

    // Run objects in a 5s loop, so the period FPS doesn't get calculated yet,
    // because we set period to 10s.
    do
    {
        // Wait single frame
        std::this_thread::sleep_for(std::chrono::milliseconds(FRAME_TIME));

        // Sum elapsed time, restart timers, increment counters.
        // Note: For FPSCounter all is done within Run() method.
        time += timer.Stop();
        timer.Start();
        a.Run();
    } while (time <= 5);

    // Get fps value.
    float counterFPS = a.GetPeriodFrameCount();

    // Period FPS should be 0, because we check too soon
    ASSERT_EQ(counterFPS, 0.0);
}