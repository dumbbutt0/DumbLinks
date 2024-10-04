# DumbLinks
**DumbLinks** is a simple C++ program designed to fetch a webpage and extract all hyperlinks from it. Utilizing the `libcurl` library, it performs HTTP requests to retrieve the HTML content of a user-specified URL. It then parses the HTML using regular expressions to find all `<a>` tags and extracts the URLs from their `href` attributes.

### **Features**

- **Fetch Web Content**: Retrieves HTML content from a given URL entered by the user.
- **Automatic Redirect Handling**: Follows HTTP redirects to fetch the final destination content.
- **Link Extraction**: Parses the HTML to extract all hyperlinks (`<a href="...">`).
- **Console Output**: Displays the list of found links directly in the console.

### **Usage**

1. **Compile the Program**:

   Ensure you have `libcurl` installed on your system. Compile the program using the following command:

   ```bash
   g++ -o link_grabber DumbLinks.cpp -lcurl
   ```

2. **Run the Program**:

   Execute the compiled program:

   ```bash
   ./link_grabber
   ```

3. **Enter the URL**:

   When prompted, input the hostname or URL from which you want to extract links:

   ```plaintext
   Enter hostname: example.com
   ```

   *Note*: If you don't include `http://` or `https://`, the program will automatically prepend `http://` to the hostname.

4. **View Extracted Links**:

   The program will fetch the webpage content, parse it, and display all found hyperlinks in the console:

   ```plaintext
   Found link: https://www.iana.org/domains/example
   ```

### **Example Output**

```plaintext
Enter hostname: example.com
URL being requested: https://example.com
Found link: https://www.iana.org/domains/example
```

### **Dependencies**

- **C++ Compiler**: A compiler that supports C++11 or later (e.g., GCC, Clang).
- **libcurl**: The curl library for handling HTTP requests.
  - Install on Debian/Ubuntu: `sudo apt-get install libcurl4-openssl-dev`
  - Install on CentOS/Fedora: `sudo dnf install libcurl-devel`

### **Limitations**

- **HTML Parsing**: Uses regular expressions for parsing HTML, which may not handle all HTML edge cases or malformed HTML.

### **Contributing**

Contributions are welcome! Feel free to submit issues or pull requests to improve the functionality or fix bugs.

### **Contact**

For any questions or suggestions, please contact [@dumbbutt0](https://x.com/dumbButt0 "My twitter handle") .
