## codegroups

---

### Description

Command-line tool that generates  a  series  of  random  5-character  code groups for Morse code practice,
and prints to standard output.

Characters are from the set:
ABCDEFGHIJKLMNOPQRSTUVWXYZ1234567890.,?/=+*.

Runs on Mac or Linux.

### Usage

Use **-c** option to choose number of groups per row.

Use **-n** option to choose total number of groups.

Combine with **mbeep** to play Morse code. See example below.

For more information, see man page.

### Build and install

* macOS

```
cd path_to_directory
make
make install
```

* Linux

```
cd path_to_directory
make
sudo make install
```

### Examples

Generate 5 rows of 5 code groups per row:

```
codegroups -c 5 -n 25
```

Play 80 code groups at 16 wpm:

```
codegroups -n 80 | mbeep -w 16 -i /dev/stdin -c
```

### License

BSD

