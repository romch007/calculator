#pragma once

#ifndef CALCULATOR_PREREQUISITES_HPP
#define CALCULATOR_PREREQUISITES_HPP

#if defined(_WIN32)
#define CALCULATOR_EXPORT __declspec(dllexport)
#define CALCULATOR_IMPORT __declspec(dllimport)
#elif defined(__ANDROID__)
#define CALCULATOR_EXPORT __attribute__((visibility("default")))
#define CALCULATOR_IMPORT __attribute__((visibility("default")))
#elif defined(__linux__)
#define CALCULATOR_EXPORT __attribute__((visibility("default")))
#define CALCULATOR_IMPORT __attribute__((visibility("default")))
#elif defined(__FreeBSD__)
#define CALCULATOR_EXPORT __attribute__((visibility("default")))
#define CALCULATOR_IMPORT __attribute__((visibility("default")))
#elif
#error "Platform not supported"
#endif

#if !defined(CALCULATOR_STATIC)
#ifdef CALCULATOR_BUILD
#define CALCULATOR_API CALCULATOR_EXPORT
#else
#define CALCULATOR_API CALCULATOR_IMPORT
#endif
#else
#define CALCULATOR_API
#endif

#endif