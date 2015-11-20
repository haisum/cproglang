/*
Conditions:

quote start if:
	" charachter is encountered
	it's not inside a comment
	it's not inside char literal: either '"' or '\"'

quote end if:
	" quote is encountered
	quote was started
	quote isn't preceeded by escape char \

multi comment start if:
	quote was not started
	single comment was not started
	/ character is encountered
	* charachter is encountered after /

multi comment end if:
	multi comment was started
	* character is encountered
	/ chacter is encountered after *

single comment start if
	quote was not started
	multi comment was not started/ character is encountered
	/ character is encountered
	/ charachter is encountered after /

single comment end if
	single comment was started
	newline was encountered

echo if
	single comment is not started
	multi comment is not started
*/