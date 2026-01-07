/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: migugar2 <migugar2@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/07 19:07:11 by migugar2          #+#    #+#             */
/*   Updated: 2026/01/07 23:34:37 by migugar2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string>
#include <iostream>
#include <fstream>
#include <cstdlib>

std::string readFile(const std::string& filename) {
  std::ifstream istrm(filename.c_str());
  if (!istrm.is_open()) {
    std::cerr << "Failed to open " << filename << std::endl;
    std::exit(EXIT_FAILURE);
  }

  std::string res;

  std::string line;
  bool first = true;
  while (std::getline(istrm, line)) {
    if (first) {
      first = false;
      res += line;
    } else {
      res += "\n" + line;
    }
  }
  istrm.close();

  return res;
}

std::string replaceCoincidences(
  const std::string& input,
  const std::string& s1,
  const std::string& s2
) {
  std::string result;
  size_t pos = 0;
  size_t repPos;
  while ((repPos = input.find(s1, pos)) != std::string::npos) {
    result.append(input, pos, repPos - pos);
    result += s2;
    pos = repPos + s1.length(); // ostrm << ifstr.substr(pos, repPos - pos) << s2;
  }
  result += input.substr(pos); // ostrm << ifstr.substr(pos);
  return result;
}

void writeInFile(const std::string& filename, std::string& str) {
  std::ofstream ostrm(filename.c_str());
  if (!ostrm.is_open()) {
    std::cerr << "Failed to open " << filename << std::endl;
    std::exit(EXIT_FAILURE);
  }

  ostrm << str;
  ostrm.close();
}

int main(int argc, char **argv) {
  if (argc != 4) {
    std::cerr << "Incorrect number of arguments: ./sed <filename> <s1> <s2>"
      << std::endl;
    return EXIT_FAILURE;
  }

  std::string s1 = argv[2];
  std::string s2 = argv[3];

  if (s1.empty()) {
    std::cerr << "s1 (replace string) cannot be empty" << std::endl;
    return EXIT_FAILURE;
  }

  std::string infileName = argv[1];
  std::string outfileName = infileName + ".replace";

  std::string ifstr = readFile(infileName);

  std::string outstr = replaceCoincidences(ifstr, s1, s2);

  writeInFile(outfileName, outstr);
}
