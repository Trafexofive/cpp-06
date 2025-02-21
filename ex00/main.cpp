/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlamkadm <mlamkadm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/17 18:46:03 by mlamkadm          #+#    #+#             */
/*   Updated: 2025/02/17 18:46:03 by mlamkadm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Scalar.hpp"

static void PrintLine(const std::string &str) {
  std::cout << ":=========================================:" << std::endl;
  std::cout << ":=====:" << str << std::endl;
  std::cout << ":=========================================:" << std::endl;
}

// int main(int ac, char **av)
// {
//     // Standard tests:
//
//     if (ac != 2)
//     {
//         std::cout << "Error: Invalid number of arguments" << std::endl;
//         return 1;
//     }else if (av[1][0] == '\0')
//     {
//         std::cout << "Error: Empty string" << std::endl;
//         return 1;
//     }
//     else {
//
//         ScalarConverter::convert(av[1]);
//     }
//
//
//
//
//     return 0;
// }

// ==================== Additional tests ==================== //

// Simple test cases:
// int main() {
//     PrintLine("Test 1: Input \"42\"");
//     ScalarConverter::convert("42");
//
//     PrintLine("Test 2: Input \"42.0f\"");
//     ScalarConverter::convert("42.0f");
//
//     PrintLine("Test 3: Input \"-42.0\"");
//     ScalarConverter::convert("-42.0");
//
//     PrintLine("Test 4: Input \"42.0f\"");
//     ScalarConverter::convert("42.0f");
//
//     PrintLine("Test 5: Input \"42.0f\"");
//     ScalarConverter::convert("42.0f");
//
//     PrintLine("Test 6: Input \"A\"");
//     ScalarConverter::convert("A");
//
//     PrintLine("Test 7: Input \"%\"");
//     ScalarConverter::convert("%");
//
//     PrintLine("Test 8: Input \"126\"");
//     ScalarConverter::convert("126");
//
//     PrintLine("Test 9: Input \"126f\"");
//     ScalarConverter::convert("126f");
//
//     PrintLine("Test 10: Input \"126.0f\"");
//     ScalarConverter::convert("126.0f");
//
//     PrintLine("Test 11: Input \"0\"");
//     ScalarConverter::convert("0");
//
//     PrintLine("Test 12: Input \"0.0f\"");
//     ScalarConverter::convert("0.0f");
//
//     PrintLine("Test 13: Input \"nan\"");
//     ScalarConverter::convert("nan");
//
//     PrintLine("Test 14: Input \"nanf\"");
//     ScalarConverter::convert("nanf");
//
//     PrintLine("Test 15: Input \"-inff\"");
//     ScalarConverter::convert("-inff");
//
//     PrintLine("Test 16: Input \"+inff\"");
//     ScalarConverter::convert("+inff");
//
//     PrintLine("Test 17: Input \"42abc\"");
//     ScalarConverter::convert("42abc");
//
//     PrintLine("Test 18: Input \"\"");
//     ScalarConverter::convert("");
//
//     PrintLine("Test 19: Input \"   \"");
//     ScalarConverter::convert("   ");
//
//     PrintLine("Test 20: Input \"-123.456f\"");
//     ScalarConverter::convert("-123.456f");
//
//     return 0;
// }


// int main() {
//   PrintLine("Test 1: Input \"    42\"");
//   ScalarConverter::convert("    42");
//   PrintLine(
//       "Expected: int: 42, float: 42.0f, double: 42.0, char: Non displayable");
//
//   PrintLine("Test 2: Input \"42    \"");
//   ScalarConverter::convert("42    ");
//   PrintLine(
//       "Expected: int: 42, float: 42.0f, double: 42.0, char: Non displayable");
//
//   PrintLine("Test 3: Input \"  42.0f  \"");
//   ScalarConverter::convert("  42.0f  ");
//   PrintLine(
//       "Expected: int: 42, float: 42.0f, double: 42.0, char: Non displayable");
//
//   PrintLine("Test 4: Input \"00042\"");
//   ScalarConverter::convert("00042");
//   PrintLine("Expected: int: 42, float: 42.0f, double: 42.0, char: '*'");
//
//   PrintLine("Test 5: Input \"0042.000f\"");
//   ScalarConverter::convert("0042.000f");
//   PrintLine("Expected: int: 42, float: 42.0f, double: 42.0, char: '*'");
//
//   PrintLine("Test 6: Input \"42.000000000000000000000000\"");
//   ScalarConverter::convert("42.000000000000000000000000");
//   PrintLine("Expected: int: 42, float: 42.0f, double: 42.0, char: '*'");
//
//   PrintLine("Test 7: Input \"42.999999999\"");
//   ScalarConverter::convert("42.999999999");
//   PrintLine("Expected: int: 42, float: 43.0f, double: 42.999999999, char: Non "
//             "displayable");
//
//   PrintLine("Test 8: Input \"-0\"");
//   ScalarConverter::convert("-0");
//   PrintLine(
//       "Expected: int: 0, float: 0.0f, double: 0.0, char: Non displayable");
//
//   PrintLine("Test 9: Input \"+42\"");
//   ScalarConverter::convert("+42");
//   PrintLine("Expected: int: 42, float: 42.0f, double: 42.0, char: '*'");
//
//   PrintLine("Test 10: Input \"  +42.0f\"");
//   ScalarConverter::convert("  +42.0f");
//   PrintLine("Expected: int: 42, float: 42.0f, double: 42.0, char: '*'");
//
//   PrintLine("Test 11: Input \"7e2\"");
//   ScalarConverter::convert("7e2");
//   PrintLine("Expected: int: 700, float: 700.0f, double: 700.0, char: Non "
//             "displayable");
//
//   PrintLine("Test 12: Input \"-7e-2\"");
//   ScalarConverter::convert("-7e-2");
//   PrintLine(
//       "Expected: int: 0, float: -0.1f, double: -0.1, char: Non displayable");
//
//   PrintLine("Test 13: Input \"NAN\"");
//   ScalarConverter::convert("NAN");
//   PrintLine(
//       "Expected: char: impossible, int: impossible, float: nanf, double: nan");
//
//   PrintLine("Test 14: Input \"inf\"");
//   ScalarConverter::convert("inf");
//   PrintLine("Expected: char: impossible, int: impossible, float: impossible, "
//             "double: impossible");
//
//   PrintLine("Test 15: Input \"-inf\"");
//   ScalarConverter::convert("-inf");
//   PrintLine("Expected: char: impossible, int: impossible, float: impossible, "
//             "double: impossible");
//
//   PrintLine("Test 16: Input \"1.7976931348623157e308\"");
//   ScalarConverter::convert("1.7976931348623157e308");
//   PrintLine("Expected: char: impossible, int: impossible, float: impossible, "
//             "double: 1.7976931348623157e+308");
//
//   PrintLine("Test 17: Input \"1e-324\"");
//   ScalarConverter::convert("1e-324");
//   PrintLine(
//       "Expected: int: 0, float: 0.0f, double: 0.0, char: Non displayable");
//
//   PrintLine("Test 18: Input \"3.4028235e38f\"");
//   ScalarConverter::convert("3.4028235e38f");
//   PrintLine("Expected: char: impossible, int: impossible, float: "
//             "340282350000000000000000000000000000000.0f (approx), double: in "
//             "scientific notation");
//
//   PrintLine("Test 19: Input \"2.2250738585072014e-308\"");
//   ScalarConverter::convert("2.2250738585072014e-308");
//   PrintLine("Expected: int: 0, float: 0.0f, double: 2.22507e-308 (approx), "
//             "char: Non displayable");
//
//   PrintLine("Test 20: Input \"0x1A\"");
//   ScalarConverter::convert("0x1A");
//   PrintLine("Expected: char: impossible, int: impossible, float: impossible, "
//             "double: impossible");
//
//   PrintLine("Test 21: Input \"   nanf   \"");
//   ScalarConverter::convert("   nanf   ");
//   PrintLine(
//       "Expected: char: impossible, int: impossible, float: nanf, double: nan");
//
//   PrintLine("Test 22: Input \"++42\"");
//   ScalarConverter::convert("++42");
//   PrintLine("Expected: char: impossible, int: impossible, float: impossible, "
//             "double: impossible");
//
//   PrintLine("Test 23: Input \"--42\"");
//   ScalarConverter::convert("--42");
//   PrintLine("Expected: char: impossible, int: impossible, float: impossible, "
//             "double: impossible");
//
//   PrintLine("Test 24: Input \"42..0\"");
//   ScalarConverter::convert("42..0");
//   PrintLine("Expected: char: impossible, int: impossible, float: impossible, "
//             "double: impossible");
//
//   PrintLine("Test 25: Input \"42.0ff\"");
//   ScalarConverter::convert("42.0ff");
//   PrintLine("Expected: char: impossible, int: impossible, float: impossible, "
//             "double: impossible");
//
//   return 0;
// }

int main() {
    PrintLine("Test 1: Input \"    +inff  \"");
    ScalarConverter::convert("    +inff  ");
    PrintLine("Expected: char: impossible, int: impossible, float: impossible, double: impossible");

    PrintLine("Test 2: Input \"-inff   \"");
    ScalarConverter::convert("-inff   ");
    PrintLine("Expected: char: impossible, int: impossible, float: impossible, double: impossible");

    PrintLine("Test 3: Input \"abc\"");
    ScalarConverter::convert("abc");
    PrintLine("Expected: char: impossible, int: impossible, float: impossible, double: impossible");

    PrintLine("Test 4: Input \"12 34\"");
    ScalarConverter::convert("12 34");
    PrintLine("Expected: char: impossible, int: impossible, float: impossible, double: impossible");

    PrintLine("Test 5: Input \" +0\"");
    ScalarConverter::convert(" +0");
    PrintLine("Expected: char: Non displayable, int: 0, float: 0.0f, double: 0.0");

    PrintLine("Test 6: Input \"-0.0\"");
    ScalarConverter::convert("-0.0");
    PrintLine("Expected: char: Non displayable, int: 0, float: 0.0f, double: 0.0");

    PrintLine("Test 7: Input \"4.2.0\"");
    ScalarConverter::convert("4.2.0");
    PrintLine("Expected: char: impossible, int: impossible, float: impossible, double: impossible");

    PrintLine("Test 8: Input \"4..2f\"");
    ScalarConverter::convert("4..2f");
    PrintLine("Expected: char: impossible, int: impossible, float: impossible, double: impossible");

    PrintLine("Test 9: Input \"\\t42\""); 
    ScalarConverter::convert("\t42");
    PrintLine("Expected: char: Non displayable, int: 42, float: 42.0f, double: 42.0");

    PrintLine("Test 10: Input \"\\n42\"");
    ScalarConverter::convert("\n42");
    PrintLine("Expected: char: Non displayable, int: 42, float: 42.0f, double: 42.0");

    PrintLine("Test 11: Input \"0xFF\"");
    ScalarConverter::convert("0xFF");
    PrintLine("Expected: char: impossible, int: impossible, float: impossible, double: impossible");

    PrintLine("Test 12: Input \"0b1010\"");
    ScalarConverter::convert("0b1010");
    PrintLine("Expected: char: impossible, int: impossible, float: impossible, double: impossible");

    PrintLine("Test 13: Input \"1e309\"");
    ScalarConverter::convert("1e309");
    PrintLine("Expected: char: impossible, int: impossible, float: impossible, double: inf or impossible");

    PrintLine("Test 14: Input \"-1e309\"");
    ScalarConverter::convert("-1e309");
    PrintLine("Expected: char: impossible, int: impossible, float: impossible, double: -inf or impossible");

    PrintLine("Test 15: Input \"2147483648\"");
    ScalarConverter::convert("2147483648");
    PrintLine("Expected: char: impossible, int: impossible, float: 2147483648.0f, double: 2147483648.0");

    PrintLine("Test 16: Input \"-2147483649\"");
    ScalarConverter::convert("-2147483649");
    PrintLine("Expected: char: impossible, int: impossible, float: -2147483649.0f, double: -2147483649.0");

    PrintLine("Test 17: Input \"9223372036854775807\"");
    ScalarConverter::convert("9223372036854775807");
    PrintLine("Expected: char: impossible, int: impossible, float: impossible, double: 9.22337e+18 approx");

    PrintLine("Test 18: Input \"3.141592653589793\"");
    ScalarConverter::convert("3.141592653589793");
    PrintLine("Expected: char: Non displayable, int: 3, float: 3.1f, double: 3.1 or 3.14 depending on rounding");

    PrintLine("Test 19: Input \"2.718281828459045f\"");
    ScalarConverter::convert("2.718281828459045f");
    PrintLine("Expected: char: Non displayable, int: 2, float: 2.7f, double: 2.7 or 2.72 depending on rounding");

    PrintLine("Test 20: Input \"NaNf\"");
    ScalarConverter::convert("NaNf");
    PrintLine("Expected: char: impossible, int: impossible, float: nanf, double: nan");

    PrintLine("Test 21: Input \"Infinity\"");
    ScalarConverter::convert("Infinity");
    PrintLine("Expected: char: impossible, int: impossible, float: impossible, double: impossible");

    PrintLine("Test 22: Input \"InfinitY\"");
    ScalarConverter::convert("InfinitY");
    PrintLine("Expected: char: impossible, int: impossible, float: impossible, double: impossible");

    PrintLine("Test 23: Input \"0.0000001\"");
    ScalarConverter::convert("0.0000001");
    PrintLine("Expected: char: Non displayable, int: 0, float: 0.0f, double: 0.0");

    PrintLine("Test 24: Input \"12345678901234567890\"");
    ScalarConverter::convert("12345678901234567890");
    PrintLine("Expected: char: impossible, int: impossible, float: 1.23457e+19f, double: 1.23457e+19");

    PrintLine("Test 25: Input \"1.0e-40\"");
    ScalarConverter::convert("1.0e-40");
    PrintLine("Expected: char: Non displayable, int: 0, float: 0.0f, double: 0.0");

    return 0;
}
