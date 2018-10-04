A simple cfg parser.

This handles simple cfg/ini like files with 'key=value' pairs.

It's really hacky, I wouldn't really trust it for anything.

Comments are ignored, they're denoted by the '#' character.

Spaces are currently treated literally. ````test=123```` and ````test = 123```` are DIFFERENT, the key has a space appended and the value a space prepended in the second example.

Duplicate keys are not handled currently, the ````cfggetvalue```` function will only give you the first value.

See settings.cfg for an example cfg file.

To compile type ````make````. Run the example program by issuing ````./example````.

All functions return 0 on failure, this goes for getting a value, always check 0 isn't returned. If it is, that means the key was not found.

Writing back to the cfg file is NOT implemented.

main.c has a usage example, however the usage structure is like this:

````
// allocate memory for the cfg structure
struct cfgfile *cfg = malloc(sizeof(struct cfgfile));
// setup cfg structure passing it the cfg structure we just made and a file name
cfgsetup(cfg, "filename.cfg");

// create a buffer for our value
char buffer[256];
// collect our value, the function returns 0 on a failure (when it cannot find the key)
int val;
val = cfggetvalue(cfg, "key", buffer, sizeof(buffer));
if (val != 0)
	puts(buffer); // print our value
else
	puts("cannot find the key!");

// free all of our memory (including cfg itself)
cfgfree(cfg);
````
