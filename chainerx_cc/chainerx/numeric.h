#pragma once
#include <cmath>

#include "chainerx/array.h"
#include "chainerx/scalar.h"

namespace chainerx {

bool AllClose(const Array& a, const Array& b, double rtol = 1e-5, double atol = 1e-8, bool equal_nan = false);

template <typename T>
inline bool IsNan(T /*value*/) {
    return false;
}

inline bool IsNan(chainerx::Float16 value) { return value.IsNan(); }
inline bool IsNan(float value) { return std::isnan(value); }
inline bool IsNan(double value) { return std::isnan(value); }

template <typename T>
inline bool IsInf(T /*value*/) {
    return false;
}

inline bool IsInf(chainerx::Float16 value) { return value.IsInf(); }
inline bool IsInf(double value) { return std::isinf(value); }
inline bool IsInf(float value) { return std::isinf(value); }

template <typename T>
inline T Tanh(T x) {
    return std::tanh(x);
}
template <>
inline chainerx::Float16 Tanh<chainerx::Float16>(chainerx::Float16 x) {
    return Float16{std::tanh(static_cast<float>(x))};
}

template <typename T>
inline T Sin(T x) {
    return std::sin(x);
}
template <>
inline chainerx::Float16 Sin<chainerx::Float16>(chainerx::Float16 x) {
    return Float16{std::sin(static_cast<float>(x))};
}

template <typename T>
inline T Cos(T x) {
    return std::cos(x);
}
template <>
inline chainerx::Float16 Cos<chainerx::Float16>(chainerx::Float16 x) {
    return Float16{std::cos(static_cast<float>(x))};
}

template <typename T>
inline T Exp(T x) {
    return std::exp(x);
}
template <>
inline chainerx::Float16 Exp<chainerx::Float16>(chainerx::Float16 x) {
    return Float16{std::exp(static_cast<float>(x))};
}

template <typename T>
inline T Log(T x) {
    return std::log(x);
}
template <>
inline chainerx::Float16 Log<chainerx::Float16>(chainerx::Float16 x) {
    return Float16{std::log(static_cast<float>(x))};
}

template <typename T>
inline T Square(T x) {
    return x * x;
}
template <>
inline chainerx::Float16 Square<chainerx::Float16>(chainerx::Float16 x) {
    return Float16{static_cast<float>(x) * static_cast<float>(x)};
}

template <typename T>
inline T Sqrt(T x) {
    return std::sqrt(x);
}
template <>
inline chainerx::Float16 Sqrt<chainerx::Float16>(chainerx::Float16 x) {
    return Float16{std::sqrt(static_cast<float>(x))};
}

template <typename T>
inline T Pow(T x1, T x2) {
    return std::pow(x1, x2);
}
template <>
inline chainerx::Float16 Pow<chainerx::Float16>(chainerx::Float16 x1, chainerx::Float16 x2) {
    return Float16{std::pow(static_cast<float>(x1), static_cast<float>(x2))};
}

}  // namespace chainerx
