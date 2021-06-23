# HTTP and everything you need to know
###### notes from an article from freecodecamp.org

At a fundamental level, when you visit a website, your browser makes an HTTP request to a server. Then that server
responds with a resource (an image, video, or the HTML of a web page) - which your browser then displays for you.

This is HTTP's message-based model. Every HTTP interaction includes a request and response.

By its nature, HTTP is stateless.

**Stateless** means that all requests are separate from each other. So each request from your browser must contain
enough information on its own for the server to fulfill the request. That also means that each transaction of the 
message based model of HTTP is processed separately from the others.

### URLs 

The URL (Uniform Resource Locator) is probably the most known concept of the Web. It is also one of the most
important and useful concepts. A URL is a web address used to identify resources on the Web.

The idea of the web is structured around resources. From its begginings the Web was the platform for sharing
text/HTML files, documents, images etc, and as such it can be considered a collection of resources.

http: --> Protocol 
//www.example.com/ --> Domain
search --> Path
?item=vw+beetle --> Parameters

http://www.example.com/search?item=vw+beetle

**Protocol**: Most often they are HTTP (or HTTPS for a secure version of HTTP).
Other notable protocols are:
    * File Transfer Protocol (FTP) - is a standard protocol used for transferring giles between a client and a
server over a network.
    * Simple Mail Transfer Protocol (SMTP) is a standard for email transmission.

**Domain**: Name that is used to identify one or more IP addresses where the resources are located.

**Path**: Specifies the resource location on the server. It uses the same logic a resource location used on the device
where you are reading this article (i.e. /search/cars/VWBeetle.pdf)

**Parameters**: Additional data used to identify or filter the resource on the server.

### HTTP Requests

In HTTP, every request must have an URL address. Additionally, the request needs a method. The four main HTTP methods
are:

* GET

* PUT

* POST

* DELETE

and these methods directly correspond to actions:

* read

* update

* create

* delete

All HTTP messages have one or more headers, followed by an optional message body. The body contains the data that will
be sent with the request or the data received with the response.

The first part of every HTTP request holds three items:

Ex: GET /adds/search-result?item=vw+beetle HTTP/1.1

When a URL contains a "?" sign, it means it contains a query. That means it sends parameters of the requested resource.

1. The first part is a method which tell which HTTP method is used. Most commonly used is the GET method. GET method retrieves
a resource from the webserver and since GET doesn't have a message body nothing after the header is needed.

1. The second part is a requested URL

1. The third part is a HTTP version being used. Version 1.1 is the most common version for most browsers, however, version 2.0 is
taking over.

### HTTP Responses

Just like in the HTTP requests, HTTP responses also consist of three items:

Example: HTTP/1.1 200 OK

1. The first part is the HTTP version being used.

1. The second part is the numeric code of the result for the request.

1. The third part is a textual description of the second part.

### HTTP Methods 

The most common methods are GET and POST. But there are a few other too.

**GET**: You use this method to request data from a specified resource where data is not modified in any way. GET requests do not change
the state of resource.

**POST**: You use this method to send data to a server to create a resource.

**PUT**: You use this method to update the existing resource on a server by using the content in the body of the request. Think of it as
a way to "edit" something.

**HEAD**: You use this method the same way you use GET, but with the distinction that the return of a HEAD method should not contain body
in the response. But the return will contain smae headers as if GET was used. You use the HEAD method to check whether the resource is 
present prior of making a GET request.

**TRACE**: You use this method for diagnostic purposes. The response will contain in its body the exact content of the request message.

**OPTIONS**: You use this method to describe the communication options (HTTP methods) that are available for the target resource.

**PATCH**: You use this method to apply partial modifications to a resource.

**DELETE**: You use this method to delete the specified resource.

### REST

Representational State Transfer (REST) is an architecture style where requests and responses contain representations of the current state
of the system resource.

"Regular" way: http://carapp.com/search?make=vw&model=beetle

REST-style: http://carapp.com/search/vw/beetle

### HTTP Headers

There are three main components that make up the request/response structure. These include:

* First line
* Headers
* Body/Content

We already talked about the first line in HTTP requests and responses, and body function was mentioned too. Now we'll talk about HTTP headers.

The HTTP headers are added after the first line and are defined as name:value pairs separated by a colon. HTTP headers are used to send additional
parameters along with the request or response.

The body of the message includes the data to be sent with the request or the data received along with the response.

There are different types of headers that are grouped based on their usage into 4 broad categories:

* **General Header**: Headers that can be used in both requests and response messages and that are independent of the data being exchanged.

* **Request Header**: These headers define parameters for the data requested or parameters that give important information about the client
making the request.

* **Response Header**: These headers contain information about the incoming response.

* **Entity Header**: The entity headers describe the content that makes up the body of the message.

### HTTP Status Codes

Browsing the web, you might have encountered "404 error: not found" pages or "500 error: server is not responding" pages. These are HTTP status
codes.

Every HTTP response message must contain an HTTP status code in its first line, telling us the result of the request. There are five groups of
status codes which are grouped by the first digit:

* 1xx - Informational.

* 2xx - The request was successful.

* 3xx - The client is redirected to a different resource.

* 4xx - The request contains an error of some kind.

* 5xx - The server encountered an error fulfilling the request.

### HTTPS (Hypertext Transfer Protocol Secure)

The secure version of HTTP protocol is HyperText Transfer Protocol Secure (HTTPS). HTTPS provides encrypted communication between a browser (client)
and the website (server).

In HTTPS, the communication protocol is encrypted using Transport Layer Security (TLS) or Secure Sockets Layer (SSL).

The protocol is therefore also often called HTTP over TLS or HTTP over SSL.

Both the TLS and SSL protocols use asymmetric encryption systems. Anyone can use the public key to encrypt a message. However, private keys are secret,
and that means that only the intended receiver can decrypt the message.

### SSL/TLS Handshake

When you request a HTTPS connection to a website, the website sends its SSL certificate to your browser. That process where your browser and website
initate communication is called the  "SSL/TLS Handshaker".

The handshake involves a series of steps where browser and website validate each other and start communication through the SSL/TLS tunnel.















