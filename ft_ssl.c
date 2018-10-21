#include <stdio.h>
#include <stdlib.h>
#include "algorithm_lookup.h"
#include "ft_ssl_module_interface.h"
#include "digest.h"

int main(int argc, char **argv) {
	initialize_modules();
	load_module_or_exit(argv[1]);
	return module_run(argc, argv);
}

/*
 * if no args:
 * 		print "usage: ft_ssl command [command opts] [command args]"
 * if first arg does not name a valid command:
 * 		print "ft_ssl: Error: '<the bad argument in question>' is an invalid command."
 * 		print "Standard commands:<list of std commands, currently empty, prefixed with \n>\n"
 * 		print "Message Digest commands:<list of digest algo names prefixed with \n>\n"
 * 		print "Cipher commands:<list of cipher commands, currently empty, prefixed with \n>\n"
 * (else we have a valid command, so:)
 * if the command name was the only argument given (argc == 2):
 * 		read from stdin
 * 		if nothing on stdin, error out. (bonus: wait for input like openssl does instead)
 * 		else: read from stdin and output the digest (don't echo input)
 * 		afterwards, exit
 * (else there were arguments, so:)
 * set awaiting_options = true
 * while awaiting_options:
 * 		if optval == -r, set use_reverse_format
 * 		if optval == -p: immediately digest stdin
 * 		if optval == -q, set quiet_mode
 * 		if optval == -s and has optarg, immediately digest the optarg
 * 		else set awaiting_options = false
 * while arguments remain:
 * 		treat each as a filename and digest its contents
 *
 * to digest a string:
 * 		initialize a new ctx with the algo named by the command arg
 * 		update the ctx with the string
 * 		finalize the ctx
 * 		set output_options.quote = true
 * 		print_formatted_output(digest, string, output_options)
 * to digest a file:
 * 		if the file does not exist or is unreadable, output an error and return
 * 		(else)
 * 		initialize a new ctx with the algo named by the command arg
 * 		while !at_eof, update the ctx with some more of the contents of the file
 * 		if not quiet_mode and fd == STDIN_FILENO, echo as you go along
 * 		finalize the ctx
 * 		set output_options.quote = false
 * 		if fd == STDIN_FILENO: print_formatted_output(digest, NULL, output_options)
 * 		else: print_formatted_output(digest, filename, output_options)
 *
 * to print a tag:
 * 		if output_options.reverse_format == false, "print <digest-algo-name-in-caps>("
 * 		if output_options.reverse_format == true, print a space
 * 		if output_options.quote = true, print a \"
 * 		print the tag
 * 		if output_options.quote = true, print a \"
 * 		if output_options.reverse_format == false, print ") = "
 *
 * to print_formatted_output(digest, tag, output_options):
 * 		if quiet_mode is set or tag == NULL, just print the digest and return
 * 		if reverse_format == false, print the digest, then print the tag
 * 		if reverse_format == true, print the tag, then print the digest
 */
