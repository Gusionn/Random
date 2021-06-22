# How the Web works
###### notes from an article by developer.mozilla.org

### Clients and Servers

Computers connected to the web are called **clients** and **servers**. A simplified diagram of how
they interact might look like this:
		     request
		-----------------> 
	Client			   Server
		<-----------------
		     responses
* Clients are the typical web user's internet-connected devices (for example, your computer connected
to your Wi-Fi, or your phone connected to your mobile network) and web-accessing software available
on those devices (usually web browsers like Firefox or Chrome).

* Servers are computers that store webpages, sites, or apps. When a client device wants to access a
webpage, a copy of the webpage is downloaded from the server onto the client machine to be displayed
in the user's web browser.

### The other parts of the toolbox

The client and the server we've described above don't tell the whole story. There are may other parts
involved.

For now, let's imagine that the web is a road. ON one end of the road is the client, which is like your house.
On the other end of the road is the server, which is a shop you want to buy something from.

In addition to the client and server, we also need to say hello to:

* **Your Internet Connection**: Allow you to send and receive data on the web. It's basically like the stret
between your house and the shop.

* **TCP/IP**: Transmission Control Protocol and Internet Protocol are communication protocols that define how
data should travel across the internet. This is like the transport mechanisms that let you place an order, go
to the shop, and buy your goods. In our example, this is like a car or a bike (or however else you might get
around),

* **DNS**: Domain Name Servers are like an address book for websites. When you type a web address in yout web
browser, the browser looks at the DNS to find the website's real address before it can retrieve the website.
The browser need to find out which server the website lives on, so it can send HTTP messages to the right place.
This is like looking up the address of the shop so you can access it.

* **HTTP**: Hypertext Transfer Protocol is an application protocol that defines a language for clients and servers
to speake to each other. This is like the language you use to order your goods.

* **Component files**: A website is made up of many different files, which are like the different parts of the
goods you buy from the shop. These files come in two main types:
    * **Code Files**: Websites are built primarily from HTML, CSS and JavaScript.
    * **Assets**: This is a collective name for all the other stuff that makes up a website, such as images, music,
video, Word documents and PDFs.

### So what happens, exactly?

When you type a web address into your web browser (for our analogy that's like walking to the shop):

1. The browser goes to the DNS server, and finds the real address of the server that the website lives on (you find
the address of the shop).

1. The browser sends an HTTP request message to the server, asking it to send a copy of the website to
the client (you go to the shop and order your goods). This message, and all other data sent between the client and 
the server, is sent across your internet connection using TCP/IP.

1. If the server approves the client's request, the server sends the client a "200 OK" message, which means 
"Of course you can look at that website! Here it is", and then starts sending the website's files to the web
browser as a series of small chunks called data packets (the shop gives you your goods, and you bring them back
to your house).

1. The browser assembles the small chunks into a complete web page and displays it to you (the goods arrive at your door).

### Order in which component files are parsed.

Once the client's request is approved, the server first sends back the HTML (index) file -- index.html is commonly
named as such, as it is the first file of a website to be parsed by the server.

The HTML file can reference CSS and JavaScript, wither in external files via <link> and <script> elements respectively,
or embedded in the HTML page via <style> and <script> elements.

From a server standpoint it is important to know the order in which these files are parsed when the response is sent back:

* The HTML file is parsed first and, by looking inside that file, the server recognises which CSS and JavaScript files are
referenced.

* After the HTML has been parsed and a DOM tree structure has been generated from it, the linked CSS is then parsed, and
styles are applied to the appropriate parts of the DOM tree. At this point, the visual representation of the page is painted
to the screen, and the user sees the page.

* The JavaScript usually gets parsed and applied to the page after the HTML and CSS.

### DNS explained

Real web addresses aren't the nice, memorable strings you type into your address bar to find your favorite websites. They are
special numbers that look like this: 63.245.215.20.

This is called an IP address, and it represents a unique location on the web. However, it's not very easy to remember, is it?
That's why Domain Name Servers were invented. These are special servers that match up a web address you type into your browser
(like "mozilla.org") to the website's real (IP) address.

Websites can be reached directly via their IP addresses. You can find the IP address of a website by typing the domain into
a tool like IP Checker.

### Packets explained

Earlier we used the term "packets" to describe the format in which the data is sent from a server to client. What do we mean
here? Basically, when data is sent across the web, it is sent in thousands of small chunks. There are multiple reasons why data is
sent in small packets. They are somethimes dropped or corrupted, and it's easier to replace small chunks when this happens.
Additionally, the packets can be routed along different paths, making the exchange faster and allowing many different users
to download the same website at the same time. If each website was sent as a single big chunk, only one user could download
it at a time, which obviously would make the web very inefficient and not much fun to use.

