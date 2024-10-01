# PA1 - UTF-8

Representing text is straightforward using ASCII: one byte per character fits well within `char*` and it represents most English text. However, there are many more than 256 characters in the text we use, from non-Latin alphabets (Cyrillic, Arabic, and Chinese character sets, etc.) to emojis and other symbols like €, to accented characters like é and ü.

The [UTF-8 encoding](https://en.wikipedia.org/wiki/UTF-8#Encoding) is the default encoding of text in the majority of software today.
If you've opened a web page, read a text message, or sent an email [in the past 15 years](https://en.wikipedia.org/wiki/UTF-8#/media/File:Unicode_Web_growth.svg) that had any special characters, the text was probably UTF-8 encoded.

Not all software handles UTF-8 correctly! For example, I got a marketing email recently with a header “Take your notes further with Connectâ€‹” I'm guessing that was supposed to be an ellipsis (…), [UTF-8 encoded as the three bytes 0xE2 0x80 0xA6](https://www.compart.com/en/unicode/U+2026), and likely the software used to author the email mishandled the encoding and treated it as [three extended ASCII characters](https://en.wikipedia.org/wiki/Extended_ASCII).

This can cause real problems for real people. For example, people with accented letters in their names can run into issues with sign-in forms (check out Twitter/X account [@yournameisvalid](https://x.com/yournameisvalid?lang=en) for some examples). People with names best written in an alphabet other than Latin can have their names mangled in official documents, and need to have a "Latinized" version of their name for business in the US.

UTF-8 bugs can and do cause security vulnerabities in products we use every day. A simple search for UTF-8 in the CVE database of security vulnerabilities turns up [hundreds of results](https://cve.mitre.org/cgi-bin/cvekey.cgi?keyword=utf-8).

It's useful to get some experience with UTF-8 so you understand how it's supposed to work and can recognize when it doesn't.
To that end, you'll write several functions that work with UTF-8 encoded text, and use them to analyze some example texts.

## Functions

### `uint8_t is_ascii(char str[])`

Takes a UTF-8 encoded string and returns if it is valid ASCII (e.g. all bytes are 127 or less).

### `uint32_t capitalize_ascii(char str[])`

Takes a UTF-8 encoded string and *changes* it in-place so that any ASCII lowercase characters `a`-`z` are changed to their uppercase versions. Leaves all other characters unchanged. It returns the number of characters updated from lowercase to uppercase.

### `uint32_t codepoint_index_to_byte_index(char str[], uint32_t codepoint_index)`

Given an utf8 encoded string, and a codepoint index, return the byte index in the string where the Unicode character at the given code point index starts. 

Example: 
```
  codepoint_index_to_byte_index("Joséph", 4) == 5;  // 4th codepoint refers character 'p'
```

### `uint32_t bytes_of_codepoint(char str[], uint32_t codepoint_index)`

Given an utf8 encoded string and codepoint_index, return the number of bytes of that codepoint.

Example:
```
  bytes_of_codepoint("Joséph", 3) == 2;  // é is 2 bytes codepoint
```

### `uint32_t codepoint_at(char str[], uint32_t codepoint_index)`

Takes a UTF-8 encoded string and a codepoint index, and returns the codepoint at that index.

Example:
```
  codepoint_at("Joséph", 4) == 'p'  // 'p' is the 4th codepoint
```

### `uint32_t utf8_code_points(char str[])`

Takes a UTF-8 encoded string and returns the number of UTF-8 code points it represents.

Example:
```
  utf8_code_points("Joséph") ==  6 
```

### `uint8_t is_animal_emoji_at(char str[], uint32_t codepoint_index)`

Takes a UTF-8 encoded string and an codepoint index, and returns if the code point at that index is an animal emoji.

For simplicity for this question, we will define that that the “animal emojii” are in two ranges: from 🐀 to 🐿️ and from 🦀 to 🦮. (Yes, this technically includes things like 🐽 which are only related to or part of an animal, and excludes a few things like 🙊, 😸, which are animal faces.). You may find the [wikipedia page on Unicode emoji](https://en.wikipedia.org/wiki/List_of_emojis) helpful here.

### `void utf8_substring(char str[], uint32_t start, uint32_t end, char result[])`

Takes a UTF-8 encoded string and start(inclusive) and end(exclusive) codepoint indices, and writes the substring between those indices to `result`, and includes a null terminator. Assumes that `result` has sufficient bytes of space available(hint: the size of the result should be known when use one of the above function).

Example:
```
  utf8_substring("🦀🦮🦮🦀🦀🦮🦮", 3, 7, result) // these emoji are 4 bytes long
  result == 🦀🦀🦮🦮
```

## UTF-8 Analyzer

You'll also write a program that reads UTF-8 input and prints out some information about it.

Here's what a sample run of your program should look like:

```
$ ./utf8analyzer
Enter a UTF-8 encoded string: My 🐩’s name is Erdős.
Valid ASCII: false
Uppercased ASCII:
Length in bytes: FILL
Number of code points: FILL
Bytes per code point: 1 1 1 4 FILL ....
Code points as decimal numbers:
Animal emojis: 🐩
Substring of the first 6 code points: "My 🐩’s"
```

You can also test the contents of _files_ by using the `<` operator:

```
$ cat utf8test.txt
FILL
$ ./utf8analyzer < utf8test.txt
Enter a UTF-8 encoded string: 
Valid ASCII: false
Uppercased ASCII:
Length in bytes: FILL
Number of code points: FILL
Bytes per code point: 1 1 1 4 FILL ....
Code points as decimal numbers:
Animal emojis: 🐩
Substring of the first 6 code points: "My 🐩’s"
```

## Testing
We provide 2 basic tests in the `tests` folder which will only grade the first few lines of your output, you can use the provided bash script to run the tests in tests folder (ex: ./test_script utfanalyzer), and it will print out result in your terminal. To test the full output of your program, you can upload your PA in gradescope, there is one public test case for you to test with. 

Here are some ideas for tests you should write. They aren't necessarily comprehensive (you should design your own!) but they should get you started. For each of these kinds of strings, you should check how UTF-8 analyzer handles them:

- Strings with a single UTF-8 character that is 1, 2, 3, 4 bytes
- Strings with two UTF-8 characters in all combinations of 1/2/3/4 bytes. (e.g. `"aa"`, `"aá"`, `"áa"`, `"áá"`, and so on)
- Strings with and without animal emojii, including at the beginning, middle, and end of the string, and at the beginning, middle, and end of the range
- Strings of exactly 5 characters

## Design Questions

Answer each of these with a few sentences or paragraphs; don't write a whole essay, but use good writing practice to communicate the essence of the idea. A good response doesn't need to be long, but it needs to have attention to detail and be clear. Examples help!

- Another encoding of Unicode is UTF-32, which encodes *all* Unicode code points in 4 bytes. For things like ASCII, the leading 3 bytes are all 0's. What are some tradeoffs between UTF-32 and UTF-8?

- UTF-8 has a leading `10` on all the bytes past the first for multi-byte code points. This seems wasteful – if the encoding for 3 bytes were instead `1110XXXX XXXXXXXX XXXXXXXX` (where `X` can be any bit), that would fit 20 bits, which is over a million code points worth of space, removing the need for a 4-byte encoding. What are some reasons this might be useful? Can you think of anything that could go wrong with some programs if the encoding didn't include this restriction on multi-byte code points?


## What to Hand In

- Any `.c` files you wrote (can be one file or many). We will run `gcc *.c -o utfanalyzer` to compile your code, so you should make sure it works when we do that.
- A file `DESIGN.md` (with exactly that name) containing the answers to the design questions
- Your tests with expected output in files `tests/*.txt`, `tests/*.txt.expect`

Hand in to the `pa1` assignment on Gradescope. The submission system will show you the output of compiling and running your program on the test input described above to make sure the baseline format of your submission works. You will not get feedback about your overall grade before the deadline.
