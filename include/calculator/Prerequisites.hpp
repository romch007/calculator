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
#elif defined(__APPLE__)
#define CALCULATOR_EXPORT __attribute__((visibility("default")))
#define CALCULATOR_IMPORT __attribute__((visibility("default")))
#elif defined(__unix__)
#include <sys/param.h>
#if defined(BSD)
#define CALCULATOR_EXPORT __attribute__((visibility("default")))
#define CALCULATOR_IMPORT __attribute__((visibility("default")))
#endif
#elif defined(__WASM__)
#define CALCULATOR_EXPORT
#define CALCULATOR_IMPORT
#else
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
