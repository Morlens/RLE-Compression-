# RLE Compression Project (CLI Version)

A C program that implements Run-Length Encoding (RLE) Compression and Decompression

- The program allows users to compress a string into its RLE format
- It also allows users to decompress an RLE string back to the original text
- Runs from the terminal using command-line arguments
- Input is read from a file and the result is written to an output file.

# How to run
Open terminal and compile the program:
```
gcc compressor.c main.c -o rleProgram.exe
```
Then run it using this syntax:
```
rleProgram.exe -c input_file output_file
rleProgram.exe -d input_file output_file
```
- **-c** to compress
- **-d** to decompress
- input_file - file to read from
- output_file - result
  
# Example
To Compress
```
rleProgram.exe -c input.txt output.txt
```
After running this command, the compressed result will be written inside output.txt.

To Decompress
```
rleProgram.exe -d output.txt result.txt
```
The decompressed result will be written inside result.txt.


