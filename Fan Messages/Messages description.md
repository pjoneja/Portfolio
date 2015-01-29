# Messages Box
A hacked-together implementation of an public comment box using Google Forms, JSON, JavaScript and HTML Tables. May not be as 'pretty' as Disqus/other comment box implementations, but this solutions allows for full administrative control over what gets posted.

### What it looks like:
![online](https://github.com/pjoneja/Portfolio-Showcase/blob/master/Fan%20Messages/MessagesBox.png)
![online](https://github.com/pjoneja/Portfolio-Showcase/blob/master/Fan%20Messages/GoogleForm.png)
![online](https://github.com/pjoneja/Portfolio-Showcase/blob/master/Fan%20Messages/Data%20Validation.png)

### Further Notes:
* Used Google Spreadsheets for extremely simple (read: basic) user experience. See screenshot above. Users can post their message WITHOUT having to create an account.
* Implement data validation (Google Form / Spreadsheet feature) to filter out vulgar languages on a school website. It's just a basic law of the Internet, when people get to be anonymous online, they tend to abuse their welcome.

### Future Improvements:
* Security: Prevent HTML/JavaScript injection attacks by 'escaping' the use of such syntax in inputs facing the user. Leverage existing frameworks such as [Zend Escaper](http://framework.zend.com/manual/current/en/modules/zend.escaper.escaping-javascript.html)
