==14774== Memcheck, a memory error detector
==14774== Copyright (C) 2002-2017, and GNU GPL'd, by Julian Seward et al.
==14774== Using Valgrind-3.15.0 and LibVEX; rerun with -h for copyright info
==14774== Command: ./lem-in
==14774== 
==14774== Invalid write of size 1
==14774==    at 0x1000047F8: ft_strcpy (ft_strcpy.c:22)
==14774==    by 0x100003717: sort_rooms_array (sort_rooms.c:58)
==14774==    by 0x10000387E: creat_rooms_array (sort_rooms.c:86)
==14774==    by 0x1000027F2: read_data (parse_.c:114)
==14774==    by 0x100003259: main (main.c:30)
==14774==  Address 0x100e19e54 is 0 bytes after a block of size 4 alloc'd
==14774==    at 0x1000AF226: malloc (in /Users/mobouzar/.brew/Cellar/valgrind/3.15.0/lib/valgrind/vgpreload_memcheck-amd64-darwin.so)
==14774==    by 0x100004614: ft_strdup (ft_strdup.c:23)
==14774==    by 0x100003854: creat_rooms_array (sort_rooms.c:83)
==14774==    by 0x1000027F2: read_data (parse_.c:114)
==14774==    by 0x100003259: main (main.c:30)
==14774== 
==14774== Invalid write of size 1
==14774==    at 0x100004811: ft_strcpy (ft_strcpy.c:25)
==14774==    by 0x100003717: sort_rooms_array (sort_rooms.c:58)
==14774==    by 0x10000387E: creat_rooms_array (sort_rooms.c:86)
==14774==    by 0x1000027F2: read_data (parse_.c:114)
==14774==    by 0x100003259: main (main.c:30)
==14774==  Address 0x100e19e55 is 1 bytes after a block of size 4 alloc'd
==14774==    at 0x1000AF226: malloc (in /Users/mobouzar/.brew/Cellar/valgrind/3.15.0/lib/valgrind/vgpreload_memcheck-amd64-darwin.so)
==14774==    by 0x100004614: ft_strdup (ft_strdup.c:23)
==14774==    by 0x100003854: creat_rooms_array (sort_rooms.c:83)
==14774==    by 0x1000027F2: read_data (parse_.c:114)
==14774==    by 0x100003259: main (main.c:30)
==14774== 
==14774== Invalid read of size 1
==14774==    at 0x1000045B8: ft_strlen (ft_strlen.c:20)
==14774==    by 0x1000049D8: ft_strcmp (ft_strcmp.c:24)
==14774==    by 0x100003672: sort_rooms_array (sort_rooms.c:51)
==14774==    by 0x10000387E: creat_rooms_array (sort_rooms.c:86)
==14774==    by 0x1000027F2: read_data (parse_.c:114)
==14774==    by 0x100003259: main (main.c:30)
==14774==  Address 0x100e19e54 is 0 bytes after a block of size 4 alloc'd
==14774==    at 0x1000AF226: malloc (in /Users/mobouzar/.brew/Cellar/valgrind/3.15.0/lib/valgrind/vgpreload_memcheck-amd64-darwin.so)
==14774==    by 0x100004614: ft_strdup (ft_strdup.c:23)
==14774==    by 0x100003854: creat_rooms_array (sort_rooms.c:83)
==14774==    by 0x1000027F2: read_data (parse_.c:114)
==14774==    by 0x100003259: main (main.c:30)
==14774== 
==14774== Invalid read of size 1
==14774==    at 0x1000049FB: ft_strcmp (ft_strcmp.c:28)
==14774==    by 0x100003672: sort_rooms_array (sort_rooms.c:51)
==14774==    by 0x10000387E: creat_rooms_array (sort_rooms.c:86)
==14774==    by 0x1000027F2: read_data (parse_.c:114)
==14774==    by 0x100003259: main (main.c:30)
==14774==  Address 0x100e19e54 is 0 bytes after a block of size 4 alloc'd
==14774==    at 0x1000AF226: malloc (in /Users/mobouzar/.brew/Cellar/valgrind/3.15.0/lib/valgrind/vgpreload_memcheck-amd64-darwin.so)
==14774==    by 0x100004614: ft_strdup (ft_strdup.c:23)
==14774==    by 0x100003854: creat_rooms_array (sort_rooms.c:83)
==14774==    by 0x1000027F2: read_data (parse_.c:114)
==14774==    by 0x100003259: main (main.c:30)
==14774== 
==14774== Invalid read of size 1
==14774==    at 0x100004A07: ft_strcmp (ft_strcmp.c:28)
==14774==    by 0x100003672: sort_rooms_array (sort_rooms.c:51)
==14774==    by 0x10000387E: creat_rooms_array (sort_rooms.c:86)
==14774==    by 0x1000027F2: read_data (parse_.c:114)
==14774==    by 0x100003259: main (main.c:30)
==14774==  Address 0x100e19e54 is 0 bytes after a block of size 4 alloc'd
==14774==    at 0x1000AF226: malloc (in /Users/mobouzar/.brew/Cellar/valgrind/3.15.0/lib/valgrind/vgpreload_memcheck-amd64-darwin.so)
==14774==    by 0x100004614: ft_strdup (ft_strdup.c:23)
==14774==    by 0x100003854: creat_rooms_array (sort_rooms.c:83)
==14774==    by 0x1000027F2: read_data (parse_.c:114)
==14774==    by 0x100003259: main (main.c:30)
==14774== 
==14774== Invalid read of size 1
==14774==    at 0x1000045B8: ft_strlen (ft_strlen.c:20)
==14774==    by 0x100003690: sort_rooms_array (sort_rooms.c:53)
==14774==    by 0x10000387E: creat_rooms_array (sort_rooms.c:86)
==14774==    by 0x1000027F2: read_data (parse_.c:114)
==14774==    by 0x100003259: main (main.c:30)
==14774==  Address 0x100e19e54 is 0 bytes after a block of size 4 alloc'd
==14774==    at 0x1000AF226: malloc (in /Users/mobouzar/.brew/Cellar/valgrind/3.15.0/lib/valgrind/vgpreload_memcheck-amd64-darwin.so)
==14774==    by 0x100004614: ft_strdup (ft_strdup.c:23)
==14774==    by 0x100003854: creat_rooms_array (sort_rooms.c:83)
==14774==    by 0x1000027F2: read_data (parse_.c:114)
==14774==    by 0x100003259: main (main.c:30)
==14774== 
==14774== Invalid read of size 1
==14774==    at 0x1000047DB: ft_strcpy (ft_strcpy.c:20)
==14774==    by 0x1000036D1: sort_rooms_array (sort_rooms.c:56)
==14774==    by 0x10000387E: creat_rooms_array (sort_rooms.c:86)
==14774==    by 0x1000027F2: read_data (parse_.c:114)
==14774==    by 0x100003259: main (main.c:30)
==14774==  Address 0x100e19e54 is 0 bytes after a block of size 4 alloc'd
==14774==    at 0x1000AF226: malloc (in /Users/mobouzar/.brew/Cellar/valgrind/3.15.0/lib/valgrind/vgpreload_memcheck-amd64-darwin.so)
==14774==    by 0x100004614: ft_strdup (ft_strdup.c:23)
==14774==    by 0x100003854: creat_rooms_array (sort_rooms.c:83)
==14774==    by 0x1000027F2: read_data (parse_.c:114)
==14774==    by 0x100003259: main (main.c:30)
==14774== 
==14774== Invalid read of size 1
==14774==    at 0x1000047ED: ft_strcpy (ft_strcpy.c:22)
==14774==    by 0x1000036D1: sort_rooms_array (sort_rooms.c:56)
==14774==    by 0x10000387E: creat_rooms_array (sort_rooms.c:86)
==14774==    by 0x1000027F2: read_data (parse_.c:114)
==14774==    by 0x100003259: main (main.c:30)
==14774==  Address 0x100e19e54 is 0 bytes after a block of size 4 alloc'd
==14774==    at 0x1000AF226: malloc (in /Users/mobouzar/.brew/Cellar/valgrind/3.15.0/lib/valgrind/vgpreload_memcheck-amd64-darwin.so)
==14774==    by 0x100004614: ft_strdup (ft_strdup.c:23)
==14774==    by 0x100003854: creat_rooms_array (sort_rooms.c:83)
==14774==    by 0x1000027F2: read_data (parse_.c:114)
==14774==    by 0x100003259: main (main.c:30)
==14774== 
==14774== Invalid read of size 1
==14774==    at 0x1000047DB: ft_strcpy (ft_strcpy.c:20)
==14774==    by 0x1000036FA: sort_rooms_array (sort_rooms.c:57)
==14774==    by 0x10000387E: creat_rooms_array (sort_rooms.c:86)
==14774==    by 0x1000027F2: read_data (parse_.c:114)
==14774==    by 0x100003259: main (main.c:30)
==14774==  Address 0x100e19ea2 is 0 bytes after a block of size 2 alloc'd
==14774==    at 0x1000AF226: malloc (in /Users/mobouzar/.brew/Cellar/valgrind/3.15.0/lib/valgrind/vgpreload_memcheck-amd64-darwin.so)
==14774==    by 0x100004614: ft_strdup (ft_strdup.c:23)
==14774==    by 0x100003854: creat_rooms_array (sort_rooms.c:83)
==14774==    by 0x1000027F2: read_data (parse_.c:114)
==14774==    by 0x100003259: main (main.c:30)
==14774== 
==14774== Invalid read of size 1
==14774==    at 0x1000047ED: ft_strcpy (ft_strcpy.c:22)
==14774==    by 0x1000036FA: sort_rooms_array (sort_rooms.c:57)
==14774==    by 0x10000387E: creat_rooms_array (sort_rooms.c:86)
==14774==    by 0x1000027F2: read_data (parse_.c:114)
==14774==    by 0x100003259: main (main.c:30)
==14774==  Address 0x100e19ea2 is 0 bytes after a block of size 2 alloc'd
==14774==    at 0x1000AF226: malloc (in /Users/mobouzar/.brew/Cellar/valgrind/3.15.0/lib/valgrind/vgpreload_memcheck-amd64-darwin.so)
==14774==    by 0x100004614: ft_strdup (ft_strdup.c:23)
==14774==    by 0x100003854: creat_rooms_array (sort_rooms.c:83)
==14774==    by 0x1000027F2: read_data (parse_.c:114)
==14774==    by 0x100003259: main (main.c:30)
==14774== 
==14774== Invalid write of size 1
==14774==    at 0x1000047F8: ft_strcpy (ft_strcpy.c:22)
==14774==    by 0x1000036FA: sort_rooms_array (sort_rooms.c:57)
==14774==    by 0x10000387E: creat_rooms_array (sort_rooms.c:86)
==14774==    by 0x1000027F2: read_data (parse_.c:114)
==14774==    by 0x100003259: main (main.c:30)
==14774==  Address 0x100e19ea2 is 0 bytes after a block of size 2 alloc'd
==14774==    at 0x1000AF226: malloc (in /Users/mobouzar/.brew/Cellar/valgrind/3.15.0/lib/valgrind/vgpreload_memcheck-amd64-darwin.so)
==14774==    by 0x100004614: ft_strdup (ft_strdup.c:23)
==14774==    by 0x100003854: creat_rooms_array (sort_rooms.c:83)
==14774==    by 0x1000027F2: read_data (parse_.c:114)
==14774==    by 0x100003259: main (main.c:30)
==14774== 
==14774== Invalid write of size 1
==14774==    at 0x100004811: ft_strcpy (ft_strcpy.c:25)
==14774==    by 0x1000036FA: sort_rooms_array (sort_rooms.c:57)
==14774==    by 0x10000387E: creat_rooms_array (sort_rooms.c:86)
==14774==    by 0x1000027F2: read_data (parse_.c:114)
==14774==    by 0x100003259: main (main.c:30)
==14774==  Address 0x100e19ea3 is 1 bytes after a block of size 2 alloc'd
==14774==    at 0x1000AF226: malloc (in /Users/mobouzar/.brew/Cellar/valgrind/3.15.0/lib/valgrind/vgpreload_memcheck-amd64-darwin.so)
==14774==    by 0x100004614: ft_strdup (ft_strdup.c:23)
==14774==    by 0x100003854: creat_rooms_array (sort_rooms.c:83)
==14774==    by 0x1000027F2: read_data (parse_.c:114)
==14774==    by 0x100003259: main (main.c:30)
==14774== 
==14774== Invalid read of size 1
==14774==    at 0x100004A1B: ft_strcmp (ft_strcmp.c:29)
==14774==    by 0x100003672: sort_rooms_array (sort_rooms.c:51)
==14774==    by 0x10000387E: creat_rooms_array (sort_rooms.c:86)
==14774==    by 0x1000027F2: read_data (parse_.c:114)
==14774==    by 0x100003259: main (main.c:30)
==14774==  Address 0x100e19ea2 is 0 bytes after a block of size 2 alloc'd
==14774==    at 0x1000AF226: malloc (in /Users/mobouzar/.brew/Cellar/valgrind/3.15.0/lib/valgrind/vgpreload_memcheck-amd64-darwin.so)
==14774==    by 0x100004614: ft_strdup (ft_strdup.c:23)
==14774==    by 0x100003854: creat_rooms_array (sort_rooms.c:83)
==14774==    by 0x1000027F2: read_data (parse_.c:114)
==14774==    by 0x100003259: main (main.c:30)
==14774== 
==14774== Invalid read of size 1
==14774==    at 0x1000045B8: ft_strlen (ft_strlen.c:20)
==14774==    by 0x1000049D8: ft_strcmp (ft_strcmp.c:24)
==14774==    by 0x100003581: ft_contains (sort_rooms.c:26)
==14774==    by 0x10000388E: creat_rooms_array (sort_rooms.c:87)
==14774==    by 0x1000027F2: read_data (parse_.c:114)
==14774==    by 0x100003259: main (main.c:30)
==14774==  Address 0x100e2d6d4 is 0 bytes after a block of size 4 alloc'd
==14774==    at 0x1000AF226: malloc (in /Users/mobouzar/.brew/Cellar/valgrind/3.15.0/lib/valgrind/vgpreload_memcheck-amd64-darwin.so)
==14774==    by 0x100004614: ft_strdup (ft_strdup.c:23)
==14774==    by 0x100003854: creat_rooms_array (sort_rooms.c:83)
==14774==    by 0x1000027F2: read_data (parse_.c:114)
==14774==    by 0x100003259: main (main.c:30)
==14774== 
==14774== Invalid read of size 1
==14774==    at 0x1000049FB: ft_strcmp (ft_strcmp.c:28)
==14774==    by 0x100003581: ft_contains (sort_rooms.c:26)
==14774==    by 0x10000388E: creat_rooms_array (sort_rooms.c:87)
==14774==    by 0x1000027F2: read_data (parse_.c:114)
==14774==    by 0x100003259: main (main.c:30)
==14774==  Address 0x100e2d6d4 is 0 bytes after a block of size 4 alloc'd
==14774==    at 0x1000AF226: malloc (in /Users/mobouzar/.brew/Cellar/valgrind/3.15.0/lib/valgrind/vgpreload_memcheck-amd64-darwin.so)
==14774==    by 0x100004614: ft_strdup (ft_strdup.c:23)
==14774==    by 0x100003854: creat_rooms_array (sort_rooms.c:83)
==14774==    by 0x1000027F2: read_data (parse_.c:114)
==14774==    by 0x100003259: main (main.c:30)
==14774== 
==14774== Invalid read of size 1
==14774==    at 0x1000045B8: ft_strlen (ft_strlen.c:20)
==14774==    by 0x1000049D8: ft_strcmp (ft_strcmp.c:24)
==14774==    by 0x100003581: ft_contains (sort_rooms.c:26)
==14774==    by 0x100002FF6: get_links (parse_.c:152)
==14774==    by 0x10000283B: read_data (parse_.c:116)
==14774==    by 0x100003259: main (main.c:30)
==14774==  Address 0x100e1b113 is 0 bytes after a block of size 3 alloc'd
==14774==    at 0x1000AF226: malloc (in /Users/mobouzar/.brew/Cellar/valgrind/3.15.0/lib/valgrind/vgpreload_memcheck-amd64-darwin.so)
==14774==    by 0x100004614: ft_strdup (ft_strdup.c:23)
==14774==    by 0x100003854: creat_rooms_array (sort_rooms.c:83)
==14774==    by 0x1000027F2: read_data (parse_.c:114)
==14774==    by 0x100003259: main (main.c:30)
==14774== 
==14774== Invalid read of size 1
==14774==    at 0x1000045B8: ft_strlen (ft_strlen.c:20)
==14774==    by 0x1000049D8: ft_strcmp (ft_strcmp.c:24)
==14774==    by 0x1000035AE: ft_contains (sort_rooms.c:28)
==14774==    by 0x100002FF6: get_links (parse_.c:152)
==14774==    by 0x10000283B: read_data (parse_.c:116)
==14774==    by 0x100003259: main (main.c:30)
==14774==  Address 0x100e1b113 is 0 bytes after a block of size 3 alloc'd
==14774==    at 0x1000AF226: malloc (in /Users/mobouzar/.brew/Cellar/valgrind/3.15.0/lib/valgrind/vgpreload_memcheck-amd64-darwin.so)
==14774==    by 0x100004614: ft_strdup (ft_strdup.c:23)
==14774==    by 0x100003854: creat_rooms_array (sort_rooms.c:83)
==14774==    by 0x1000027F2: read_data (parse_.c:114)
==14774==    by 0x100003259: main (main.c:30)
==14774== 
==14774== Invalid read of size 1
==14774==    at 0x1000045B8: ft_strlen (ft_strlen.c:20)
==14774==    by 0x1000049D8: ft_strcmp (ft_strcmp.c:24)
==14774==    by 0x100003581: ft_contains (sort_rooms.c:26)
==14774==    by 0x100003016: get_links (parse_.c:153)
==14774==    by 0x10000283B: read_data (parse_.c:116)
==14774==    by 0x100003259: main (main.c:30)
==14774==  Address 0x100e1b113 is 0 bytes after a block of size 3 alloc'd
==14774==    at 0x1000AF226: malloc (in /Users/mobouzar/.brew/Cellar/valgrind/3.15.0/lib/valgrind/vgpreload_memcheck-amd64-darwin.so)
==14774==    by 0x100004614: ft_strdup (ft_strdup.c:23)
==14774==    by 0x100003854: creat_rooms_array (sort_rooms.c:83)
==14774==    by 0x1000027F2: read_data (parse_.c:114)
==14774==    by 0x100003259: main (main.c:30)
==14774== 
==14774== Invalid read of size 1
==14774==    at 0x1000045B8: ft_strlen (ft_strlen.c:20)
==14774==    by 0x1000049D8: ft_strcmp (ft_strcmp.c:24)
==14774==    by 0x1000035AE: ft_contains (sort_rooms.c:28)
==14774==    by 0x100003016: get_links (parse_.c:153)
==14774==    by 0x10000283B: read_data (parse_.c:116)
==14774==    by 0x100003259: main (main.c:30)
==14774==  Address 0x100e1b113 is 0 bytes after a block of size 3 alloc'd
==14774==    at 0x1000AF226: malloc (in /Users/mobouzar/.brew/Cellar/valgrind/3.15.0/lib/valgrind/vgpreload_memcheck-amd64-darwin.so)
==14774==    by 0x100004614: ft_strdup (ft_strdup.c:23)
==14774==    by 0x100003854: creat_rooms_array (sort_rooms.c:83)
==14774==    by 0x1000027F2: read_data (parse_.c:114)
==14774==    by 0x100003259: main (main.c:30)
==14774== 
==14774== Invalid read of size 1
==14774==    at 0x1000049FB: ft_strcmp (ft_strcmp.c:28)
==14774==    by 0x100003581: ft_contains (sort_rooms.c:26)
==14774==    by 0x100003016: get_links (parse_.c:153)
==14774==    by 0x10000283B: read_data (parse_.c:116)
==14774==    by 0x100003259: main (main.c:30)
==14774==  Address 0x100e1a2b3 is 0 bytes after a block of size 3 alloc'd
==14774==    at 0x1000AF226: malloc (in /Users/mobouzar/.brew/Cellar/valgrind/3.15.0/lib/valgrind/vgpreload_memcheck-amd64-darwin.so)
==14774==    by 0x100004614: ft_strdup (ft_strdup.c:23)
==14774==    by 0x100003854: creat_rooms_array (sort_rooms.c:83)
==14774==    by 0x1000027F2: read_data (parse_.c:114)
==14774==    by 0x100003259: main (main.c:30)
==14774== 
==14774== Invalid read of size 1
==14774==    at 0x1000049FB: ft_strcmp (ft_strcmp.c:28)
==14774==    by 0x100003581: ft_contains (sort_rooms.c:26)
==14774==    by 0x100002FF6: get_links (parse_.c:152)
==14774==    by 0x10000283B: read_data (parse_.c:116)
==14774==    by 0x100003259: main (main.c:30)
==14774==  Address 0x100e19fe2 is 0 bytes after a block of size 2 alloc'd
==14774==    at 0x1000AF226: malloc (in /Users/mobouzar/.brew/Cellar/valgrind/3.15.0/lib/valgrind/vgpreload_memcheck-amd64-darwin.so)
==14774==    by 0x100004614: ft_strdup (ft_strdup.c:23)
==14774==    by 0x100003854: creat_rooms_array (sort_rooms.c:83)
==14774==    by 0x1000027F2: read_data (parse_.c:114)
==14774==    by 0x100003259: main (main.c:30)
==14774== 
==14774== Invalid read of size 1
==14774==    at 0x100004A1B: ft_strcmp (ft_strcmp.c:29)
==14774==    by 0x100003581: ft_contains (sort_rooms.c:26)
==14774==    by 0x100002FF6: get_links (parse_.c:152)
==14774==    by 0x10000283B: read_data (parse_.c:116)
==14774==    by 0x100003259: main (main.c:30)
==14774==  Address 0x100e19fe2 is 0 bytes after a block of size 2 alloc'd
==14774==    at 0x1000AF226: malloc (in /Users/mobouzar/.brew/Cellar/valgrind/3.15.0/lib/valgrind/vgpreload_memcheck-amd64-darwin.so)
==14774==    by 0x100004614: ft_strdup (ft_strdup.c:23)
==14774==    by 0x100003854: creat_rooms_array (sort_rooms.c:83)
==14774==    by 0x1000027F2: read_data (parse_.c:114)
==14774==    by 0x100003259: main (main.c:30)
==14774== 
==14774== Invalid read of size 1
==14774==    at 0x1000049FB: ft_strcmp (ft_strcmp.c:28)
==14774==    by 0x1000035AE: ft_contains (sort_rooms.c:28)
==14774==    by 0x100002FF6: get_links (parse_.c:152)
==14774==    by 0x10000283B: read_data (parse_.c:116)
==14774==    by 0x100003259: main (main.c:30)
==14774==  Address 0x100e19fe2 is 0 bytes after a block of size 2 alloc'd
==14774==    at 0x1000AF226: malloc (in /Users/mobouzar/.brew/Cellar/valgrind/3.15.0/lib/valgrind/vgpreload_memcheck-amd64-darwin.so)
==14774==    by 0x100004614: ft_strdup (ft_strdup.c:23)
==14774==    by 0x100003854: creat_rooms_array (sort_rooms.c:83)
==14774==    by 0x1000027F2: read_data (parse_.c:114)
==14774==    by 0x100003259: main (main.c:30)
==14774== 
==14774== Invalid read of size 1
==14774==    at 0x100004A1B: ft_strcmp (ft_strcmp.c:29)
==14774==    by 0x1000035AE: ft_contains (sort_rooms.c:28)
==14774==    by 0x100002FF6: get_links (parse_.c:152)
==14774==    by 0x10000283B: read_data (parse_.c:116)
==14774==    by 0x100003259: main (main.c:30)
==14774==  Address 0x100e19fe2 is 0 bytes after a block of size 2 alloc'd
==14774==    at 0x1000AF226: malloc (in /Users/mobouzar/.brew/Cellar/valgrind/3.15.0/lib/valgrind/vgpreload_memcheck-amd64-darwin.so)
==14774==    by 0x100004614: ft_strdup (ft_strdup.c:23)
==14774==    by 0x100003854: creat_rooms_array (sort_rooms.c:83)
==14774==    by 0x1000027F2: read_data (parse_.c:114)
==14774==    by 0x100003259: main (main.c:30)
==14774== 
==14774== Invalid read of size 1
==14774==    at 0x100004A1B: ft_strcmp (ft_strcmp.c:29)
==14774==    by 0x100003581: ft_contains (sort_rooms.c:26)
==14774==    by 0x100003016: get_links (parse_.c:153)
==14774==    by 0x10000283B: read_data (parse_.c:116)
==14774==    by 0x100003259: main (main.c:30)
==14774==  Address 0x100e19fe2 is 0 bytes after a block of size 2 alloc'd
==14774==    at 0x1000AF226: malloc (in /Users/mobouzar/.brew/Cellar/valgrind/3.15.0/lib/valgrind/vgpreload_memcheck-amd64-darwin.so)
==14774==    by 0x100004614: ft_strdup (ft_strdup.c:23)
==14774==    by 0x100003854: creat_rooms_array (sort_rooms.c:83)
==14774==    by 0x1000027F2: read_data (parse_.c:114)
==14774==    by 0x100003259: main (main.c:30)
==14774== 
==14774== Invalid read of size 1
==14774==    at 0x1000049FB: ft_strcmp (ft_strcmp.c:28)
==14774==    by 0x1000035AE: ft_contains (sort_rooms.c:28)
==14774==    by 0x100003016: get_links (parse_.c:153)
==14774==    by 0x10000283B: read_data (parse_.c:116)
==14774==    by 0x100003259: main (main.c:30)
==14774==  Address 0x100e19fe2 is 0 bytes after a block of size 2 alloc'd
==14774==    at 0x1000AF226: malloc (in /Users/mobouzar/.brew/Cellar/valgrind/3.15.0/lib/valgrind/vgpreload_memcheck-amd64-darwin.so)
==14774==    by 0x100004614: ft_strdup (ft_strdup.c:23)
==14774==    by 0x100003854: creat_rooms_array (sort_rooms.c:83)
==14774==    by 0x1000027F2: read_data (parse_.c:114)
==14774==    by 0x100003259: main (main.c:30)
==14774== 
==14774== Invalid read of size 1
==14774==    at 0x100004A1B: ft_strcmp (ft_strcmp.c:29)
==14774==    by 0x1000035AE: ft_contains (sort_rooms.c:28)
==14774==    by 0x100003016: get_links (parse_.c:153)
==14774==    by 0x10000283B: read_data (parse_.c:116)
==14774==    by 0x100003259: main (main.c:30)
==14774==  Address 0x100e19fe2 is 0 bytes after a block of size 2 alloc'd
==14774==    at 0x1000AF226: malloc (in /Users/mobouzar/.brew/Cellar/valgrind/3.15.0/lib/valgrind/vgpreload_memcheck-amd64-darwin.so)
==14774==    by 0x100004614: ft_strdup (ft_strdup.c:23)
==14774==    by 0x100003854: creat_rooms_array (sort_rooms.c:83)
==14774==    by 0x1000027F2: read_data (parse_.c:114)
==14774==    by 0x100003259: main (main.c:30)
==14774== 
==14774== Invalid read of size 1
==14774==    at 0x1000045B8: ft_strlen (ft_strlen.c:20)
==14774==    by 0x1000045FB: ft_strdup (ft_strdup.c:22)
==14774==    by 0x1000040B3: ft_get_ (ft_get_nbr_path.c:37)
==14774==    by 0x100003FAF: ft_get_node_name (ft_get_nbr_path.c:54)
==14774==    by 0x100003E88: ft_get_ants_start (ft_get_nbr_path.c:83)
==14774==    by 0x100003D42: ft_chang_path (ft_get_nbr_path.c:105)
==14774==    by 0x100003912: ft_print_instructoin (print_instructoin.c:94)
==14774==    by 0x1000041B5: ft_mangement_instructoin (ft_mangement.c:109)
==14774==    by 0x1000032A9: main (main.c:38)
==14774==  Address 0x100e2d6d4 is 0 bytes after a block of size 4 alloc'd
==14774==    at 0x1000AF226: malloc (in /Users/mobouzar/.brew/Cellar/valgrind/3.15.0/lib/valgrind/vgpreload_memcheck-amd64-darwin.so)
==14774==    by 0x100004614: ft_strdup (ft_strdup.c:23)
==14774==    by 0x100003854: creat_rooms_array (sort_rooms.c:83)
==14774==    by 0x1000027F2: read_data (parse_.c:114)
==14774==    by 0x100003259: main (main.c:30)
==14774== 
==14774== Invalid read of size 1
==14774==    at 0x10000463D: ft_strdup (ft_strdup.c:25)
==14774==    by 0x1000040B3: ft_get_ (ft_get_nbr_path.c:37)
==14774==    by 0x100003FAF: ft_get_node_name (ft_get_nbr_path.c:54)
==14774==    by 0x100003E88: ft_get_ants_start (ft_get_nbr_path.c:83)
==14774==    by 0x100003D42: ft_chang_path (ft_get_nbr_path.c:105)
==14774==    by 0x100003912: ft_print_instructoin (print_instructoin.c:94)
==14774==    by 0x1000041B5: ft_mangement_instructoin (ft_mangement.c:109)
==14774==    by 0x1000032A9: main (main.c:38)
==14774==  Address 0x100e2d6d4 is 0 bytes after a block of size 4 alloc'd
==14774==    at 0x1000AF226: malloc (in /Users/mobouzar/.brew/Cellar/valgrind/3.15.0/lib/valgrind/vgpreload_memcheck-amd64-darwin.so)
==14774==    by 0x100004614: ft_strdup (ft_strdup.c:23)
==14774==    by 0x100003854: creat_rooms_array (sort_rooms.c:83)
==14774==    by 0x1000027F2: read_data (parse_.c:114)
==14774==    by 0x100003259: main (main.c:30)
==14774== 
==14774== Invalid read of size 1
==14774==    at 0x10000464F: ft_strdup (ft_strdup.c:27)
==14774==    by 0x1000040B3: ft_get_ (ft_get_nbr_path.c:37)
==14774==    by 0x100003FAF: ft_get_node_name (ft_get_nbr_path.c:54)
==14774==    by 0x100003E88: ft_get_ants_start (ft_get_nbr_path.c:83)
==14774==    by 0x100003D42: ft_chang_path (ft_get_nbr_path.c:105)
==14774==    by 0x100003912: ft_print_instructoin (print_instructoin.c:94)
==14774==    by 0x1000041B5: ft_mangement_instructoin (ft_mangement.c:109)
==14774==    by 0x1000032A9: main (main.c:38)
==14774==  Address 0x100e2d6d4 is 0 bytes after a block of size 4 alloc'd
==14774==    at 0x1000AF226: malloc (in /Users/mobouzar/.brew/Cellar/valgrind/3.15.0/lib/valgrind/vgpreload_memcheck-amd64-darwin.so)
==14774==    by 0x100004614: ft_strdup (ft_strdup.c:23)
==14774==    by 0x100003854: creat_rooms_array (sort_rooms.c:83)
==14774==    by 0x1000027F2: read_data (parse_.c:114)
==14774==    by 0x100003259: main (main.c:30)
==14774== 
==14774== Invalid read of size 1
==14774==    at 0x1000045B8: ft_strlen (ft_strlen.c:20)
==14774==    by 0x1000045FB: ft_strdup (ft_strdup.c:22)
==14774==    by 0x1000040B3: ft_get_ (ft_get_nbr_path.c:37)
==14774==    by 0x100003FEA: ft_get_node_name (ft_get_nbr_path.c:59)
==14774==    by 0x100003E88: ft_get_ants_start (ft_get_nbr_path.c:83)
==14774==    by 0x100003D42: ft_chang_path (ft_get_nbr_path.c:105)
==14774==    by 0x100003912: ft_print_instructoin (print_instructoin.c:94)
==14774==    by 0x1000041B5: ft_mangement_instructoin (ft_mangement.c:109)
==14774==    by 0x1000032A9: main (main.c:38)
==14774==  Address 0x100e1a623 is 0 bytes after a block of size 3 alloc'd
==14774==    at 0x1000AF226: malloc (in /Users/mobouzar/.brew/Cellar/valgrind/3.15.0/lib/valgrind/vgpreload_memcheck-amd64-darwin.so)
==14774==    by 0x100004614: ft_strdup (ft_strdup.c:23)
==14774==    by 0x100003854: creat_rooms_array (sort_rooms.c:83)
==14774==    by 0x1000027F2: read_data (parse_.c:114)
==14774==    by 0x100003259: main (main.c:30)
==14774== 
==14774== Invalid read of size 1
==14774==    at 0x10000463D: ft_strdup (ft_strdup.c:25)
==14774==    by 0x1000040B3: ft_get_ (ft_get_nbr_path.c:37)
==14774==    by 0x100003FEA: ft_get_node_name (ft_get_nbr_path.c:59)
==14774==    by 0x100003E88: ft_get_ants_start (ft_get_nbr_path.c:83)
==14774==    by 0x100003D42: ft_chang_path (ft_get_nbr_path.c:105)
==14774==    by 0x100003912: ft_print_instructoin (print_instructoin.c:94)
==14774==    by 0x1000041B5: ft_mangement_instructoin (ft_mangement.c:109)
==14774==    by 0x1000032A9: main (main.c:38)
==14774==  Address 0x100e1a623 is 0 bytes after a block of size 3 alloc'd
==14774==    at 0x1000AF226: malloc (in /Users/mobouzar/.brew/Cellar/valgrind/3.15.0/lib/valgrind/vgpreload_memcheck-amd64-darwin.so)
==14774==    by 0x100004614: ft_strdup (ft_strdup.c:23)
==14774==    by 0x100003854: creat_rooms_array (sort_rooms.c:83)
==14774==    by 0x1000027F2: read_data (parse_.c:114)
==14774==    by 0x100003259: main (main.c:30)
==14774== 
==14774== 
==14774== HEAP SUMMARY:
==14774==     in use at exit: 18,283 bytes in 161 blocks
==14774==   total heap usage: 144,470 allocs, 144,309 frees, 1,125,642 bytes allocated
==14774== 
==14774== 24 bytes in 1 blocks are still reachable in loss record 3 of 41
==14774==    at 0x1000AF49E: malloc_zone_malloc (in /Users/mobouzar/.brew/Cellar/valgrind/3.15.0/lib/valgrind/vgpreload_memcheck-amd64-darwin.so)
==14774==    by 0x1005CA8A6: NXCreateMapTableFromZone (in /usr/lib/libobjc.A.dylib)
==14774==    by 0x1005CA878: NXCreateMapTableFromZone (in /usr/lib/libobjc.A.dylib)
==14774==    by 0x1005C9350: __sel_registerName(char const*, int, int) (in /usr/lib/libobjc.A.dylib)
==14774==    by 0x1005C9062: sel_init (in /usr/lib/libobjc.A.dylib)
==14774==    by 0x1005C89CA: map_images_nolock (in /usr/lib/libobjc.A.dylib)
==14774==    by 0x1005DBFE8: objc_object::sidetable_retainCount() (in /usr/lib/libobjc.A.dylib)
==14774==    by 0x10001F03B: dyld::notifyBatchPartial(dyld_image_states, bool, char const* (*)(dyld_image_states, unsigned int, dyld_image_info const*), bool, bool) (in /usr/lib/dyld)
==14774==    by 0x10001F255: dyld::registerObjCNotifiers(void (*)(unsigned int, char const* const*, mach_header const* const*), void (*)(char const*, mach_header const*), void (*)(char const*, mach_header const*)) (in /usr/lib/dyld)
==14774==    by 0x10021600A: _dyld_objc_notify_register (in /usr/lib/system/libdyld.dylib)
==14774==    by 0x1005C8074: _objc_init (in /usr/lib/libobjc.A.dylib)
==14774==    by 0x1001A968D: _os_object_init (in /usr/lib/system/libdispatch.dylib)
==14774== 
==14774== 32 bytes in 1 blocks are still reachable in loss record 7 of 41
==14774==    at 0x1000AF49E: malloc_zone_malloc (in /Users/mobouzar/.brew/Cellar/valgrind/3.15.0/lib/valgrind/vgpreload_memcheck-amd64-darwin.so)
==14774==    by 0x1005CA9FE: NXCreateHashTableFromZone (in /usr/lib/libobjc.A.dylib)
==14774==    by 0x1005CA9CE: NXCreateHashTable (in /usr/lib/libobjc.A.dylib)
==14774==    by 0x1005CA8CE: NXCreateMapTableFromZone (in /usr/lib/libobjc.A.dylib)
==14774==    by 0x1005CA878: NXCreateMapTableFromZone (in /usr/lib/libobjc.A.dylib)
==14774==    by 0x1005C9350: __sel_registerName(char const*, int, int) (in /usr/lib/libobjc.A.dylib)
==14774==    by 0x1005C9062: sel_init (in /usr/lib/libobjc.A.dylib)
==14774==    by 0x1005C89CA: map_images_nolock (in /usr/lib/libobjc.A.dylib)
==14774==    by 0x1005DBFE8: objc_object::sidetable_retainCount() (in /usr/lib/libobjc.A.dylib)
==14774==    by 0x10001F03B: dyld::notifyBatchPartial(dyld_image_states, bool, char const* (*)(dyld_image_states, unsigned int, dyld_image_info const*), bool, bool) (in /usr/lib/dyld)
==14774==    by 0x10001F255: dyld::registerObjCNotifiers(void (*)(unsigned int, char const* const*, mach_header const* const*), void (*)(char const*, mach_header const*), void (*)(char const*, mach_header const*)) (in /usr/lib/dyld)
==14774==    by 0x10021600A: _dyld_objc_notify_register (in /usr/lib/system/libdyld.dylib)
==14774== 
==14774== 32 bytes in 1 blocks are still reachable in loss record 8 of 41
==14774==    at 0x1000AF49E: malloc_zone_malloc (in /Users/mobouzar/.brew/Cellar/valgrind/3.15.0/lib/valgrind/vgpreload_memcheck-amd64-darwin.so)
==14774==    by 0x1005CAA1F: NXCreateHashTableFromZone (in /usr/lib/libobjc.A.dylib)
==14774==    by 0x1005CA9CE: NXCreateHashTable (in /usr/lib/libobjc.A.dylib)
==14774==    by 0x1005CA8CE: NXCreateMapTableFromZone (in /usr/lib/libobjc.A.dylib)
==14774==    by 0x1005CA878: NXCreateMapTableFromZone (in /usr/lib/libobjc.A.dylib)
==14774==    by 0x1005C9350: __sel_registerName(char const*, int, int) (in /usr/lib/libobjc.A.dylib)
==14774==    by 0x1005C9062: sel_init (in /usr/lib/libobjc.A.dylib)
==14774==    by 0x1005C89CA: map_images_nolock (in /usr/lib/libobjc.A.dylib)
==14774==    by 0x1005DBFE8: objc_object::sidetable_retainCount() (in /usr/lib/libobjc.A.dylib)
==14774==    by 0x10001F03B: dyld::notifyBatchPartial(dyld_image_states, bool, char const* (*)(dyld_image_states, unsigned int, dyld_image_info const*), bool, bool) (in /usr/lib/dyld)
==14774==    by 0x10001F255: dyld::registerObjCNotifiers(void (*)(unsigned int, char const* const*, mach_header const* const*), void (*)(char const*, mach_header const*), void (*)(char const*, mach_header const*)) (in /usr/lib/dyld)
==14774==    by 0x10021600A: _dyld_objc_notify_register (in /usr/lib/system/libdyld.dylib)
==14774== 
==14774== 32 bytes in 1 blocks are still reachable in loss record 9 of 41
==14774==    at 0x1000AF226: malloc (in /Users/mobouzar/.brew/Cellar/valgrind/3.15.0/lib/valgrind/vgpreload_memcheck-amd64-darwin.so)
==14774==    by 0x1005CAAE3: NXCreateHashTableFromZone (in /usr/lib/libobjc.A.dylib)
==14774==    by 0x1005CA9CE: NXCreateHashTable (in /usr/lib/libobjc.A.dylib)
==14774==    by 0x1005CA8CE: NXCreateMapTableFromZone (in /usr/lib/libobjc.A.dylib)
==14774==    by 0x1005CA878: NXCreateMapTableFromZone (in /usr/lib/libobjc.A.dylib)
==14774==    by 0x1005C9350: __sel_registerName(char const*, int, int) (in /usr/lib/libobjc.A.dylib)
==14774==    by 0x1005C9062: sel_init (in /usr/lib/libobjc.A.dylib)
==14774==    by 0x1005C89CA: map_images_nolock (in /usr/lib/libobjc.A.dylib)
==14774==    by 0x1005DBFE8: objc_object::sidetable_retainCount() (in /usr/lib/libobjc.A.dylib)
==14774==    by 0x10001F03B: dyld::notifyBatchPartial(dyld_image_states, bool, char const* (*)(dyld_image_states, unsigned int, dyld_image_info const*), bool, bool) (in /usr/lib/dyld)
==14774==    by 0x10001F255: dyld::registerObjCNotifiers(void (*)(unsigned int, char const* const*, mach_header const* const*), void (*)(char const*, mach_header const*), void (*)(char const*, mach_header const*)) (in /usr/lib/dyld)
==14774==    by 0x10021600A: _dyld_objc_notify_register (in /usr/lib/system/libdyld.dylib)
==14774== 
==14774== 32 bytes in 1 blocks are still reachable in loss record 10 of 41
==14774==    at 0x1000AF226: malloc (in /Users/mobouzar/.brew/Cellar/valgrind/3.15.0/lib/valgrind/vgpreload_memcheck-amd64-darwin.so)
==14774==    by 0x1005CA934: NXCreateMapTableFromZone (in /usr/lib/libobjc.A.dylib)
==14774==    by 0x1005CA878: NXCreateMapTableFromZone (in /usr/lib/libobjc.A.dylib)
==14774==    by 0x1005C9350: __sel_registerName(char const*, int, int) (in /usr/lib/libobjc.A.dylib)
==14774==    by 0x1005C9062: sel_init (in /usr/lib/libobjc.A.dylib)
==14774==    by 0x1005C89CA: map_images_nolock (in /usr/lib/libobjc.A.dylib)
==14774==    by 0x1005DBFE8: objc_object::sidetable_retainCount() (in /usr/lib/libobjc.A.dylib)
==14774==    by 0x10001F03B: dyld::notifyBatchPartial(dyld_image_states, bool, char const* (*)(dyld_image_states, unsigned int, dyld_image_info const*), bool, bool) (in /usr/lib/dyld)
==14774==    by 0x10001F255: dyld::registerObjCNotifiers(void (*)(unsigned int, char const* const*, mach_header const* const*), void (*)(char const*, mach_header const*), void (*)(char const*, mach_header const*)) (in /usr/lib/dyld)
==14774==    by 0x10021600A: _dyld_objc_notify_register (in /usr/lib/system/libdyld.dylib)
==14774==    by 0x1005C8074: _objc_init (in /usr/lib/libobjc.A.dylib)
==14774==    by 0x1001A968D: _os_object_init (in /usr/lib/system/libdispatch.dylib)
==14774== 
==14774== 48 bytes in 1 blocks are still reachable in loss record 14 of 41
==14774==    at 0x1000AFA4D: malloc_zone_calloc (in /Users/mobouzar/.brew/Cellar/valgrind/3.15.0/lib/valgrind/vgpreload_memcheck-amd64-darwin.so)
==14774==    by 0x1005CAEC6: _NXHashRehashToCapacity (in /usr/lib/libobjc.A.dylib)
==14774==    by 0x1005CAE50: NXHashInsert (in /usr/lib/libobjc.A.dylib)
==14774==    by 0x1005CAB0D: NXCreateHashTableFromZone (in /usr/lib/libobjc.A.dylib)
==14774==    by 0x1005CA9CE: NXCreateHashTable (in /usr/lib/libobjc.A.dylib)
==14774==    by 0x1005CA8CE: NXCreateMapTableFromZone (in /usr/lib/libobjc.A.dylib)
==14774==    by 0x1005CA878: NXCreateMapTableFromZone (in /usr/lib/libobjc.A.dylib)
==14774==    by 0x1005C9350: __sel_registerName(char const*, int, int) (in /usr/lib/libobjc.A.dylib)
==14774==    by 0x1005C9062: sel_init (in /usr/lib/libobjc.A.dylib)
==14774==    by 0x1005C89CA: map_images_nolock (in /usr/lib/libobjc.A.dylib)
==14774==    by 0x1005DBFE8: objc_object::sidetable_retainCount() (in /usr/lib/libobjc.A.dylib)
==14774==    by 0x10001F03B: dyld::notifyBatchPartial(dyld_image_states, bool, char const* (*)(dyld_image_states, unsigned int, dyld_image_info const*), bool, bool) (in /usr/lib/dyld)
==14774== 
==14774== 72 bytes in 3 blocks are possibly lost in loss record 25 of 41
==14774==    at 0x1000AF88A: calloc (in /Users/mobouzar/.brew/Cellar/valgrind/3.15.0/lib/valgrind/vgpreload_memcheck-amd64-darwin.so)
==14774==    by 0x1005C8846: map_images_nolock (in /usr/lib/libobjc.A.dylib)
==14774==    by 0x1005DBFE8: objc_object::sidetable_retainCount() (in /usr/lib/libobjc.A.dylib)
==14774==    by 0x10001F03B: dyld::notifyBatchPartial(dyld_image_states, bool, char const* (*)(dyld_image_states, unsigned int, dyld_image_info const*), bool, bool) (in /usr/lib/dyld)
==14774==    by 0x10001F255: dyld::registerObjCNotifiers(void (*)(unsigned int, char const* const*, mach_header const* const*), void (*)(char const*, mach_header const*), void (*)(char const*, mach_header const*)) (in /usr/lib/dyld)
==14774==    by 0x10021600A: _dyld_objc_notify_register (in /usr/lib/system/libdyld.dylib)
==14774==    by 0x1005C8074: _objc_init (in /usr/lib/libobjc.A.dylib)
==14774==    by 0x1001A968D: _os_object_init (in /usr/lib/system/libdispatch.dylib)
==14774==    by 0x1001A963A: libdispatch_init (in /usr/lib/system/libdispatch.dylib)
==14774==    by 0x1000BD9D5: libSystem_initializer (in /usr/lib/libSystem.B.dylib)
==14774==    by 0x10002FA1A: ImageLoaderMachO::doModInitFunctions(ImageLoader::LinkContext const&) (in /usr/lib/dyld)
==14774==    by 0x10002FC1D: ImageLoaderMachO::doInitialization(ImageLoader::LinkContext const&) (in /usr/lib/dyld)
==14774== 
==14774== LEAK SUMMARY:
==14774==    definitely lost: 0 bytes in 0 blocks
==14774==    indirectly lost: 0 bytes in 0 blocks
==14774==      possibly lost: 72 bytes in 3 blocks
==14774==    still reachable: 200 bytes in 6 blocks
==14774==         suppressed: 18,011 bytes in 152 blocks
==14774== 
==14774== ERROR SUMMARY: 109425 errors from 33 contexts (suppressed: 11 from 11)
==14774== 
==14774== 2 errors in context 1 of 33:
==14774== Invalid read of size 1
==14774==    at 0x10000463D: ft_strdup (ft_strdup.c:25)
==14774==    by 0x1000040B3: ft_get_ (ft_get_nbr_path.c:37)
==14774==    by 0x100003FEA: ft_get_node_name (ft_get_nbr_path.c:59)
==14774==    by 0x100003E88: ft_get_ants_start (ft_get_nbr_path.c:83)
==14774==    by 0x100003D42: ft_chang_path (ft_get_nbr_path.c:105)
==14774==    by 0x100003912: ft_print_instructoin (print_instructoin.c:94)
==14774==    by 0x1000041B5: ft_mangement_instructoin (ft_mangement.c:109)
==14774==    by 0x1000032A9: main (main.c:38)
==14774==  Address 0x100e1a623 is 0 bytes after a block of size 3 alloc'd
==14774==    at 0x1000AF226: malloc (in /Users/mobouzar/.brew/Cellar/valgrind/3.15.0/lib/valgrind/vgpreload_memcheck-amd64-darwin.so)
==14774==    by 0x100004614: ft_strdup (ft_strdup.c:23)
==14774==    by 0x100003854: creat_rooms_array (sort_rooms.c:83)
==14774==    by 0x1000027F2: read_data (parse_.c:114)
==14774==    by 0x100003259: main (main.c:30)
==14774== 
==14774== 
==14774== 2 errors in context 2 of 33:
==14774== Invalid read of size 1
==14774==    at 0x1000045B8: ft_strlen (ft_strlen.c:20)
==14774==    by 0x1000045FB: ft_strdup (ft_strdup.c:22)
==14774==    by 0x1000040B3: ft_get_ (ft_get_nbr_path.c:37)
==14774==    by 0x100003FEA: ft_get_node_name (ft_get_nbr_path.c:59)
==14774==    by 0x100003E88: ft_get_ants_start (ft_get_nbr_path.c:83)
==14774==    by 0x100003D42: ft_chang_path (ft_get_nbr_path.c:105)
==14774==    by 0x100003912: ft_print_instructoin (print_instructoin.c:94)
==14774==    by 0x1000041B5: ft_mangement_instructoin (ft_mangement.c:109)
==14774==    by 0x1000032A9: main (main.c:38)
==14774==  Address 0x100e1a623 is 0 bytes after a block of size 3 alloc'd
==14774==    at 0x1000AF226: malloc (in /Users/mobouzar/.brew/Cellar/valgrind/3.15.0/lib/valgrind/vgpreload_memcheck-amd64-darwin.so)
==14774==    by 0x100004614: ft_strdup (ft_strdup.c:23)
==14774==    by 0x100003854: creat_rooms_array (sort_rooms.c:83)
==14774==    by 0x1000027F2: read_data (parse_.c:114)
==14774==    by 0x100003259: main (main.c:30)
==14774== 
==14774== 
==14774== 2 errors in context 3 of 33:
==14774== Invalid read of size 1
==14774==    at 0x1000049FB: ft_strcmp (ft_strcmp.c:28)
==14774==    by 0x100003581: ft_contains (sort_rooms.c:26)
==14774==    by 0x10000388E: creat_rooms_array (sort_rooms.c:87)
==14774==    by 0x1000027F2: read_data (parse_.c:114)
==14774==    by 0x100003259: main (main.c:30)
==14774==  Address 0x100e2d6d4 is 0 bytes after a block of size 4 alloc'd
==14774==    at 0x1000AF226: malloc (in /Users/mobouzar/.brew/Cellar/valgrind/3.15.0/lib/valgrind/vgpreload_memcheck-amd64-darwin.so)
==14774==    by 0x100004614: ft_strdup (ft_strdup.c:23)
==14774==    by 0x100003854: creat_rooms_array (sort_rooms.c:83)
==14774==    by 0x1000027F2: read_data (parse_.c:114)
==14774==    by 0x100003259: main (main.c:30)
==14774== 
==14774== 
==14774== 2 errors in context 4 of 33:
==14774== Invalid read of size 1
==14774==    at 0x1000045B8: ft_strlen (ft_strlen.c:20)
==14774==    by 0x1000049D8: ft_strcmp (ft_strcmp.c:24)
==14774==    by 0x100003581: ft_contains (sort_rooms.c:26)
==14774==    by 0x10000388E: creat_rooms_array (sort_rooms.c:87)
==14774==    by 0x1000027F2: read_data (parse_.c:114)
==14774==    by 0x100003259: main (main.c:30)
==14774==  Address 0x100e2d6d4 is 0 bytes after a block of size 4 alloc'd
==14774==    at 0x1000AF226: malloc (in /Users/mobouzar/.brew/Cellar/valgrind/3.15.0/lib/valgrind/vgpreload_memcheck-amd64-darwin.so)
==14774==    by 0x100004614: ft_strdup (ft_strdup.c:23)
==14774==    by 0x100003854: creat_rooms_array (sort_rooms.c:83)
==14774==    by 0x1000027F2: read_data (parse_.c:114)
==14774==    by 0x100003259: main (main.c:30)
==14774== 
==14774== 
==14774== 3 errors in context 5 of 33:
==14774== Invalid read of size 1
==14774==    at 0x10000464F: ft_strdup (ft_strdup.c:27)
==14774==    by 0x1000040B3: ft_get_ (ft_get_nbr_path.c:37)
==14774==    by 0x100003FAF: ft_get_node_name (ft_get_nbr_path.c:54)
==14774==    by 0x100003E88: ft_get_ants_start (ft_get_nbr_path.c:83)
==14774==    by 0x100003D42: ft_chang_path (ft_get_nbr_path.c:105)
==14774==    by 0x100003912: ft_print_instructoin (print_instructoin.c:94)
==14774==    by 0x1000041B5: ft_mangement_instructoin (ft_mangement.c:109)
==14774==    by 0x1000032A9: main (main.c:38)
==14774==  Address 0x100e2d6d4 is 0 bytes after a block of size 4 alloc'd
==14774==    at 0x1000AF226: malloc (in /Users/mobouzar/.brew/Cellar/valgrind/3.15.0/lib/valgrind/vgpreload_memcheck-amd64-darwin.so)
==14774==    by 0x100004614: ft_strdup (ft_strdup.c:23)
==14774==    by 0x100003854: creat_rooms_array (sort_rooms.c:83)
==14774==    by 0x1000027F2: read_data (parse_.c:114)
==14774==    by 0x100003259: main (main.c:30)
==14774== 
==14774== 
==14774== 6 errors in context 6 of 33:
==14774== Invalid read of size 1
==14774==    at 0x10000463D: ft_strdup (ft_strdup.c:25)
==14774==    by 0x1000040B3: ft_get_ (ft_get_nbr_path.c:37)
==14774==    by 0x100003FAF: ft_get_node_name (ft_get_nbr_path.c:54)
==14774==    by 0x100003E88: ft_get_ants_start (ft_get_nbr_path.c:83)
==14774==    by 0x100003D42: ft_chang_path (ft_get_nbr_path.c:105)
==14774==    by 0x100003912: ft_print_instructoin (print_instructoin.c:94)
==14774==    by 0x1000041B5: ft_mangement_instructoin (ft_mangement.c:109)
==14774==    by 0x1000032A9: main (main.c:38)
==14774==  Address 0x100e2d6d4 is 0 bytes after a block of size 4 alloc'd
==14774==    at 0x1000AF226: malloc (in /Users/mobouzar/.brew/Cellar/valgrind/3.15.0/lib/valgrind/vgpreload_memcheck-amd64-darwin.so)
==14774==    by 0x100004614: ft_strdup (ft_strdup.c:23)
==14774==    by 0x100003854: creat_rooms_array (sort_rooms.c:83)
==14774==    by 0x1000027F2: read_data (parse_.c:114)
==14774==    by 0x100003259: main (main.c:30)
==14774== 
==14774== 
==14774== 6 errors in context 7 of 33:
==14774== Invalid read of size 1
==14774==    at 0x1000045B8: ft_strlen (ft_strlen.c:20)
==14774==    by 0x1000045FB: ft_strdup (ft_strdup.c:22)
==14774==    by 0x1000040B3: ft_get_ (ft_get_nbr_path.c:37)
==14774==    by 0x100003FAF: ft_get_node_name (ft_get_nbr_path.c:54)
==14774==    by 0x100003E88: ft_get_ants_start (ft_get_nbr_path.c:83)
==14774==    by 0x100003D42: ft_chang_path (ft_get_nbr_path.c:105)
==14774==    by 0x100003912: ft_print_instructoin (print_instructoin.c:94)
==14774==    by 0x1000041B5: ft_mangement_instructoin (ft_mangement.c:109)
==14774==    by 0x1000032A9: main (main.c:38)
==14774==  Address 0x100e2d6d4 is 0 bytes after a block of size 4 alloc'd
==14774==    at 0x1000AF226: malloc (in /Users/mobouzar/.brew/Cellar/valgrind/3.15.0/lib/valgrind/vgpreload_memcheck-amd64-darwin.so)
==14774==    by 0x100004614: ft_strdup (ft_strdup.c:23)
==14774==    by 0x100003854: creat_rooms_array (sort_rooms.c:83)
==14774==    by 0x1000027F2: read_data (parse_.c:114)
==14774==    by 0x100003259: main (main.c:30)
==14774== 
==14774== 
==14774== 10 errors in context 8 of 33:
==14774== Invalid read of size 1
==14774==    at 0x1000047ED: ft_strcpy (ft_strcpy.c:22)
==14774==    by 0x1000036FA: sort_rooms_array (sort_rooms.c:57)
==14774==    by 0x10000387E: creat_rooms_array (sort_rooms.c:86)
==14774==    by 0x1000027F2: read_data (parse_.c:114)
==14774==    by 0x100003259: main (main.c:30)
==14774==  Address 0x100e19ea2 is 0 bytes after a block of size 2 alloc'd
==14774==    at 0x1000AF226: malloc (in /Users/mobouzar/.brew/Cellar/valgrind/3.15.0/lib/valgrind/vgpreload_memcheck-amd64-darwin.so)
==14774==    by 0x100004614: ft_strdup (ft_strdup.c:23)
==14774==    by 0x100003854: creat_rooms_array (sort_rooms.c:83)
==14774==    by 0x1000027F2: read_data (parse_.c:114)
==14774==    by 0x100003259: main (main.c:30)
==14774== 
==14774== 
==14774== 19 errors in context 9 of 33:
==14774== Invalid write of size 1
==14774==    at 0x1000047F8: ft_strcpy (ft_strcpy.c:22)
==14774==    by 0x1000036FA: sort_rooms_array (sort_rooms.c:57)
==14774==    by 0x10000387E: creat_rooms_array (sort_rooms.c:86)
==14774==    by 0x1000027F2: read_data (parse_.c:114)
==14774==    by 0x100003259: main (main.c:30)
==14774==  Address 0x100e19ea2 is 0 bytes after a block of size 2 alloc'd
==14774==    at 0x1000AF226: malloc (in /Users/mobouzar/.brew/Cellar/valgrind/3.15.0/lib/valgrind/vgpreload_memcheck-amd64-darwin.so)
==14774==    by 0x100004614: ft_strdup (ft_strdup.c:23)
==14774==    by 0x100003854: creat_rooms_array (sort_rooms.c:83)
==14774==    by 0x1000027F2: read_data (parse_.c:114)
==14774==    by 0x100003259: main (main.c:30)
==14774== 
==14774== 
==14774== 36 errors in context 10 of 33:
==14774== Invalid read of size 1
==14774==    at 0x100004A1B: ft_strcmp (ft_strcmp.c:29)
==14774==    by 0x1000035AE: ft_contains (sort_rooms.c:28)
==14774==    by 0x100002FF6: get_links (parse_.c:152)
==14774==    by 0x10000283B: read_data (parse_.c:116)
==14774==    by 0x100003259: main (main.c:30)
==14774==  Address 0x100e19fe2 is 0 bytes after a block of size 2 alloc'd
==14774==    at 0x1000AF226: malloc (in /Users/mobouzar/.brew/Cellar/valgrind/3.15.0/lib/valgrind/vgpreload_memcheck-amd64-darwin.so)
==14774==    by 0x100004614: ft_strdup (ft_strdup.c:23)
==14774==    by 0x100003854: creat_rooms_array (sort_rooms.c:83)
==14774==    by 0x1000027F2: read_data (parse_.c:114)
==14774==    by 0x100003259: main (main.c:30)
==14774== 
==14774== 
==14774== 36 errors in context 11 of 33:
==14774== Invalid read of size 1
==14774==    at 0x1000049FB: ft_strcmp (ft_strcmp.c:28)
==14774==    by 0x1000035AE: ft_contains (sort_rooms.c:28)
==14774==    by 0x100002FF6: get_links (parse_.c:152)
==14774==    by 0x10000283B: read_data (parse_.c:116)
==14774==    by 0x100003259: main (main.c:30)
==14774==  Address 0x100e19fe2 is 0 bytes after a block of size 2 alloc'd
==14774==    at 0x1000AF226: malloc (in /Users/mobouzar/.brew/Cellar/valgrind/3.15.0/lib/valgrind/vgpreload_memcheck-amd64-darwin.so)
==14774==    by 0x100004614: ft_strdup (ft_strdup.c:23)
==14774==    by 0x100003854: creat_rooms_array (sort_rooms.c:83)
==14774==    by 0x1000027F2: read_data (parse_.c:114)
==14774==    by 0x100003259: main (main.c:30)
==14774== 
==14774== 
==14774== 36 errors in context 12 of 33:
==14774== Invalid read of size 1
==14774==    at 0x100004A1B: ft_strcmp (ft_strcmp.c:29)
==14774==    by 0x100003581: ft_contains (sort_rooms.c:26)
==14774==    by 0x100002FF6: get_links (parse_.c:152)
==14774==    by 0x10000283B: read_data (parse_.c:116)
==14774==    by 0x100003259: main (main.c:30)
==14774==  Address 0x100e19fe2 is 0 bytes after a block of size 2 alloc'd
==14774==    at 0x1000AF226: malloc (in /Users/mobouzar/.brew/Cellar/valgrind/3.15.0/lib/valgrind/vgpreload_memcheck-amd64-darwin.so)
==14774==    by 0x100004614: ft_strdup (ft_strdup.c:23)
==14774==    by 0x100003854: creat_rooms_array (sort_rooms.c:83)
==14774==    by 0x1000027F2: read_data (parse_.c:114)
==14774==    by 0x100003259: main (main.c:30)
==14774== 
==14774== 
==14774== 50 errors in context 13 of 33:
==14774== Invalid read of size 1
==14774==    at 0x100004A1B: ft_strcmp (ft_strcmp.c:29)
==14774==    by 0x1000035AE: ft_contains (sort_rooms.c:28)
==14774==    by 0x100003016: get_links (parse_.c:153)
==14774==    by 0x10000283B: read_data (parse_.c:116)
==14774==    by 0x100003259: main (main.c:30)
==14774==  Address 0x100e19fe2 is 0 bytes after a block of size 2 alloc'd
==14774==    at 0x1000AF226: malloc (in /Users/mobouzar/.brew/Cellar/valgrind/3.15.0/lib/valgrind/vgpreload_memcheck-amd64-darwin.so)
==14774==    by 0x100004614: ft_strdup (ft_strdup.c:23)
==14774==    by 0x100003854: creat_rooms_array (sort_rooms.c:83)
==14774==    by 0x1000027F2: read_data (parse_.c:114)
==14774==    by 0x100003259: main (main.c:30)
==14774== 
==14774== 
==14774== 50 errors in context 14 of 33:
==14774== Invalid read of size 1
==14774==    at 0x1000049FB: ft_strcmp (ft_strcmp.c:28)
==14774==    by 0x1000035AE: ft_contains (sort_rooms.c:28)
==14774==    by 0x100003016: get_links (parse_.c:153)
==14774==    by 0x10000283B: read_data (parse_.c:116)
==14774==    by 0x100003259: main (main.c:30)
==14774==  Address 0x100e19fe2 is 0 bytes after a block of size 2 alloc'd
==14774==    at 0x1000AF226: malloc (in /Users/mobouzar/.brew/Cellar/valgrind/3.15.0/lib/valgrind/vgpreload_memcheck-amd64-darwin.so)
==14774==    by 0x100004614: ft_strdup (ft_strdup.c:23)
==14774==    by 0x100003854: creat_rooms_array (sort_rooms.c:83)
==14774==    by 0x1000027F2: read_data (parse_.c:114)
==14774==    by 0x100003259: main (main.c:30)
==14774== 
==14774== 
==14774== 50 errors in context 15 of 33:
==14774== Invalid read of size 1
==14774==    at 0x100004A1B: ft_strcmp (ft_strcmp.c:29)
==14774==    by 0x100003581: ft_contains (sort_rooms.c:26)
==14774==    by 0x100003016: get_links (parse_.c:153)
==14774==    by 0x10000283B: read_data (parse_.c:116)
==14774==    by 0x100003259: main (main.c:30)
==14774==  Address 0x100e19fe2 is 0 bytes after a block of size 2 alloc'd
==14774==    at 0x1000AF226: malloc (in /Users/mobouzar/.brew/Cellar/valgrind/3.15.0/lib/valgrind/vgpreload_memcheck-amd64-darwin.so)
==14774==    by 0x100004614: ft_strdup (ft_strdup.c:23)
==14774==    by 0x100003854: creat_rooms_array (sort_rooms.c:83)
==14774==    by 0x1000027F2: read_data (parse_.c:114)
==14774==    by 0x100003259: main (main.c:30)
==14774== 
==14774== 
==14774== 55 errors in context 16 of 33:
==14774== Invalid read of size 1
==14774==    at 0x100004A1B: ft_strcmp (ft_strcmp.c:29)
==14774==    by 0x100003672: sort_rooms_array (sort_rooms.c:51)
==14774==    by 0x10000387E: creat_rooms_array (sort_rooms.c:86)
==14774==    by 0x1000027F2: read_data (parse_.c:114)
==14774==    by 0x100003259: main (main.c:30)
==14774==  Address 0x100e19ea2 is 0 bytes after a block of size 2 alloc'd
==14774==    at 0x1000AF226: malloc (in /Users/mobouzar/.brew/Cellar/valgrind/3.15.0/lib/valgrind/vgpreload_memcheck-amd64-darwin.so)
==14774==    by 0x100004614: ft_strdup (ft_strdup.c:23)
==14774==    by 0x100003854: creat_rooms_array (sort_rooms.c:83)
==14774==    by 0x1000027F2: read_data (parse_.c:114)
==14774==    by 0x100003259: main (main.c:30)
==14774== 
==14774== 
==14774== 110 errors in context 17 of 33:
==14774== Invalid read of size 1
==14774==    at 0x1000047DB: ft_strcpy (ft_strcpy.c:20)
==14774==    by 0x1000036FA: sort_rooms_array (sort_rooms.c:57)
==14774==    by 0x10000387E: creat_rooms_array (sort_rooms.c:86)
==14774==    by 0x1000027F2: read_data (parse_.c:114)
==14774==    by 0x100003259: main (main.c:30)
==14774==  Address 0x100e19ea2 is 0 bytes after a block of size 2 alloc'd
==14774==    at 0x1000AF226: malloc (in /Users/mobouzar/.brew/Cellar/valgrind/3.15.0/lib/valgrind/vgpreload_memcheck-amd64-darwin.so)
==14774==    by 0x100004614: ft_strdup (ft_strdup.c:23)
==14774==    by 0x100003854: creat_rooms_array (sort_rooms.c:83)
==14774==    by 0x1000027F2: read_data (parse_.c:114)
==14774==    by 0x100003259: main (main.c:30)
==14774== 
==14774== 
==14774== 236 errors in context 18 of 33:
==14774== Invalid write of size 1
==14774==    at 0x100004811: ft_strcpy (ft_strcpy.c:25)
==14774==    by 0x1000036FA: sort_rooms_array (sort_rooms.c:57)
==14774==    by 0x10000387E: creat_rooms_array (sort_rooms.c:86)
==14774==    by 0x1000027F2: read_data (parse_.c:114)
==14774==    by 0x100003259: main (main.c:30)
==14774==  Address 0x100e19ea3 is 1 bytes after a block of size 2 alloc'd
==14774==    at 0x1000AF226: malloc (in /Users/mobouzar/.brew/Cellar/valgrind/3.15.0/lib/valgrind/vgpreload_memcheck-amd64-darwin.so)
==14774==    by 0x100004614: ft_strdup (ft_strdup.c:23)
==14774==    by 0x100003854: creat_rooms_array (sort_rooms.c:83)
==14774==    by 0x1000027F2: read_data (parse_.c:114)
==14774==    by 0x100003259: main (main.c:30)
==14774== 
==14774== 
==14774== 241 errors in context 19 of 33:
==14774== Invalid read of size 1
==14774==    at 0x1000049FB: ft_strcmp (ft_strcmp.c:28)
==14774==    by 0x100003581: ft_contains (sort_rooms.c:26)
==14774==    by 0x100002FF6: get_links (parse_.c:152)
==14774==    by 0x10000283B: read_data (parse_.c:116)
==14774==    by 0x100003259: main (main.c:30)
==14774==  Address 0x100e19fe2 is 0 bytes after a block of size 2 alloc'd
==14774==    at 0x1000AF226: malloc (in /Users/mobouzar/.brew/Cellar/valgrind/3.15.0/lib/valgrind/vgpreload_memcheck-amd64-darwin.so)
==14774==    by 0x100004614: ft_strdup (ft_strdup.c:23)
==14774==    by 0x100003854: creat_rooms_array (sort_rooms.c:83)
==14774==    by 0x1000027F2: read_data (parse_.c:114)
==14774==    by 0x100003259: main (main.c:30)
==14774== 
==14774== 
==14774== 274 errors in context 20 of 33:
==14774== Invalid read of size 1
==14774==    at 0x1000049FB: ft_strcmp (ft_strcmp.c:28)
==14774==    by 0x100003581: ft_contains (sort_rooms.c:26)
==14774==    by 0x100003016: get_links (parse_.c:153)
==14774==    by 0x10000283B: read_data (parse_.c:116)
==14774==    by 0x100003259: main (main.c:30)
==14774==  Address 0x100e1a2b3 is 0 bytes after a block of size 3 alloc'd
==14774==    at 0x1000AF226: malloc (in /Users/mobouzar/.brew/Cellar/valgrind/3.15.0/lib/valgrind/vgpreload_memcheck-amd64-darwin.so)
==14774==    by 0x100004614: ft_strdup (ft_strdup.c:23)
==14774==    by 0x100003854: creat_rooms_array (sort_rooms.c:83)
==14774==    by 0x1000027F2: read_data (parse_.c:114)
==14774==    by 0x100003259: main (main.c:30)
==14774== 
==14774== 
==14774== 1059 errors in context 21 of 33:
==14774== Invalid read of size 1
==14774==    at 0x1000045B8: ft_strlen (ft_strlen.c:20)
==14774==    by 0x1000049D8: ft_strcmp (ft_strcmp.c:24)
==14774==    by 0x1000035AE: ft_contains (sort_rooms.c:28)
==14774==    by 0x100002FF6: get_links (parse_.c:152)
==14774==    by 0x10000283B: read_data (parse_.c:116)
==14774==    by 0x100003259: main (main.c:30)
==14774==  Address 0x100e1b113 is 0 bytes after a block of size 3 alloc'd
==14774==    at 0x1000AF226: malloc (in /Users/mobouzar/.brew/Cellar/valgrind/3.15.0/lib/valgrind/vgpreload_memcheck-amd64-darwin.so)
==14774==    by 0x100004614: ft_strdup (ft_strdup.c:23)
==14774==    by 0x100003854: creat_rooms_array (sort_rooms.c:83)
==14774==    by 0x1000027F2: read_data (parse_.c:114)
==14774==    by 0x100003259: main (main.c:30)
==14774== 
==14774== 
==14774== 1101 errors in context 22 of 33:
==14774== Invalid write of size 1
==14774==    at 0x100004811: ft_strcpy (ft_strcpy.c:25)
==14774==    by 0x100003717: sort_rooms_array (sort_rooms.c:58)
==14774==    by 0x10000387E: creat_rooms_array (sort_rooms.c:86)
==14774==    by 0x1000027F2: read_data (parse_.c:114)
==14774==    by 0x100003259: main (main.c:30)
==14774==  Address 0x100e19e55 is 1 bytes after a block of size 4 alloc'd
==14774==    at 0x1000AF226: malloc (in /Users/mobouzar/.brew/Cellar/valgrind/3.15.0/lib/valgrind/vgpreload_memcheck-amd64-darwin.so)
==14774==    by 0x100004614: ft_strdup (ft_strdup.c:23)
==14774==    by 0x100003854: creat_rooms_array (sort_rooms.c:83)
==14774==    by 0x1000027F2: read_data (parse_.c:114)
==14774==    by 0x100003259: main (main.c:30)
==14774== 
==14774== 
==14774== 1120 errors in context 23 of 33:
==14774== Invalid read of size 1
==14774==    at 0x1000047ED: ft_strcpy (ft_strcpy.c:22)
==14774==    by 0x1000036D1: sort_rooms_array (sort_rooms.c:56)
==14774==    by 0x10000387E: creat_rooms_array (sort_rooms.c:86)
==14774==    by 0x1000027F2: read_data (parse_.c:114)
==14774==    by 0x100003259: main (main.c:30)
==14774==  Address 0x100e19e54 is 0 bytes after a block of size 4 alloc'd
==14774==    at 0x1000AF226: malloc (in /Users/mobouzar/.brew/Cellar/valgrind/3.15.0/lib/valgrind/vgpreload_memcheck-amd64-darwin.so)
==14774==    by 0x100004614: ft_strdup (ft_strdup.c:23)
==14774==    by 0x100003854: creat_rooms_array (sort_rooms.c:83)
==14774==    by 0x1000027F2: read_data (parse_.c:114)
==14774==    by 0x100003259: main (main.c:30)
==14774== 
==14774== 
==14774== 1121 errors in context 24 of 33:
==14774== Invalid write of size 1
==14774==    at 0x1000047F8: ft_strcpy (ft_strcpy.c:22)
==14774==    by 0x100003717: sort_rooms_array (sort_rooms.c:58)
==14774==    by 0x10000387E: creat_rooms_array (sort_rooms.c:86)
==14774==    by 0x1000027F2: read_data (parse_.c:114)
==14774==    by 0x100003259: main (main.c:30)
==14774==  Address 0x100e19e54 is 0 bytes after a block of size 4 alloc'd
==14774==    at 0x1000AF226: malloc (in /Users/mobouzar/.brew/Cellar/valgrind/3.15.0/lib/valgrind/vgpreload_memcheck-amd64-darwin.so)
==14774==    by 0x100004614: ft_strdup (ft_strdup.c:23)
==14774==    by 0x100003854: creat_rooms_array (sort_rooms.c:83)
==14774==    by 0x1000027F2: read_data (parse_.c:114)
==14774==    by 0x100003259: main (main.c:30)
==14774== 
==14774== 
==14774== 1209 errors in context 25 of 33:
==14774== Invalid read of size 1
==14774==    at 0x1000045B8: ft_strlen (ft_strlen.c:20)
==14774==    by 0x1000049D8: ft_strcmp (ft_strcmp.c:24)
==14774==    by 0x1000035AE: ft_contains (sort_rooms.c:28)
==14774==    by 0x100003016: get_links (parse_.c:153)
==14774==    by 0x10000283B: read_data (parse_.c:116)
==14774==    by 0x100003259: main (main.c:30)
==14774==  Address 0x100e1b113 is 0 bytes after a block of size 3 alloc'd
==14774==    at 0x1000AF226: malloc (in /Users/mobouzar/.brew/Cellar/valgrind/3.15.0/lib/valgrind/vgpreload_memcheck-amd64-darwin.so)
==14774==    by 0x100004614: ft_strdup (ft_strdup.c:23)
==14774==    by 0x100003854: creat_rooms_array (sort_rooms.c:83)
==14774==    by 0x1000027F2: read_data (parse_.c:114)
==14774==    by 0x100003259: main (main.c:30)
==14774== 
==14774== 
==14774== 1264 errors in context 26 of 33:
==14774== Invalid read of size 1
==14774==    at 0x1000045B8: ft_strlen (ft_strlen.c:20)
==14774==    by 0x1000049D8: ft_strcmp (ft_strcmp.c:24)
==14774==    by 0x100003581: ft_contains (sort_rooms.c:26)
==14774==    by 0x100002FF6: get_links (parse_.c:152)
==14774==    by 0x10000283B: read_data (parse_.c:116)
==14774==    by 0x100003259: main (main.c:30)
==14774==  Address 0x100e1b113 is 0 bytes after a block of size 3 alloc'd
==14774==    at 0x1000AF226: malloc (in /Users/mobouzar/.brew/Cellar/valgrind/3.15.0/lib/valgrind/vgpreload_memcheck-amd64-darwin.so)
==14774==    by 0x100004614: ft_strdup (ft_strdup.c:23)
==14774==    by 0x100003854: creat_rooms_array (sort_rooms.c:83)
==14774==    by 0x1000027F2: read_data (parse_.c:114)
==14774==    by 0x100003259: main (main.c:30)
==14774== 
==14774== 
==14774== 1433 errors in context 27 of 33:
==14774== Invalid read of size 1
==14774==    at 0x1000045B8: ft_strlen (ft_strlen.c:20)
==14774==    by 0x1000049D8: ft_strcmp (ft_strcmp.c:24)
==14774==    by 0x100003581: ft_contains (sort_rooms.c:26)
==14774==    by 0x100003016: get_links (parse_.c:153)
==14774==    by 0x10000283B: read_data (parse_.c:116)
==14774==    by 0x100003259: main (main.c:30)
==14774==  Address 0x100e1b113 is 0 bytes after a block of size 3 alloc'd
==14774==    at 0x1000AF226: malloc (in /Users/mobouzar/.brew/Cellar/valgrind/3.15.0/lib/valgrind/vgpreload_memcheck-amd64-darwin.so)
==14774==    by 0x100004614: ft_strdup (ft_strdup.c:23)
==14774==    by 0x100003854: creat_rooms_array (sort_rooms.c:83)
==14774==    by 0x1000027F2: read_data (parse_.c:114)
==14774==    by 0x100003259: main (main.c:30)
==14774== 
==14774== 
==14774== 2112 errors in context 28 of 33:
==14774== Invalid read of size 1
==14774==    at 0x100004A07: ft_strcmp (ft_strcmp.c:28)
==14774==    by 0x100003672: sort_rooms_array (sort_rooms.c:51)
==14774==    by 0x10000387E: creat_rooms_array (sort_rooms.c:86)
==14774==    by 0x1000027F2: read_data (parse_.c:114)
==14774==    by 0x100003259: main (main.c:30)
==14774==  Address 0x100e19e54 is 0 bytes after a block of size 4 alloc'd
==14774==    at 0x1000AF226: malloc (in /Users/mobouzar/.brew/Cellar/valgrind/3.15.0/lib/valgrind/vgpreload_memcheck-amd64-darwin.so)
==14774==    by 0x100004614: ft_strdup (ft_strdup.c:23)
==14774==    by 0x100003854: creat_rooms_array (sort_rooms.c:83)
==14774==    by 0x1000027F2: read_data (parse_.c:114)
==14774==    by 0x100003259: main (main.c:30)
==14774== 
==14774== 
==14774== 2167 errors in context 29 of 33:
==14774== Invalid read of size 1
==14774==    at 0x1000049FB: ft_strcmp (ft_strcmp.c:28)
==14774==    by 0x100003672: sort_rooms_array (sort_rooms.c:51)
==14774==    by 0x10000387E: creat_rooms_array (sort_rooms.c:86)
==14774==    by 0x1000027F2: read_data (parse_.c:114)
==14774==    by 0x100003259: main (main.c:30)
==14774==  Address 0x100e19e54 is 0 bytes after a block of size 4 alloc'd
==14774==    at 0x1000AF226: malloc (in /Users/mobouzar/.brew/Cellar/valgrind/3.15.0/lib/valgrind/vgpreload_memcheck-amd64-darwin.so)
==14774==    by 0x100004614: ft_strdup (ft_strdup.c:23)
==14774==    by 0x100003854: creat_rooms_array (sort_rooms.c:83)
==14774==    by 0x1000027F2: read_data (parse_.c:114)
==14774==    by 0x100003259: main (main.c:30)
==14774== 
==14774== 
==14774== 2265 errors in context 30 of 33:
==14774== Invalid read of size 1
==14774==    at 0x1000047DB: ft_strcpy (ft_strcpy.c:20)
==14774==    by 0x1000036D1: sort_rooms_array (sort_rooms.c:56)
==14774==    by 0x10000387E: creat_rooms_array (sort_rooms.c:86)
==14774==    by 0x1000027F2: read_data (parse_.c:114)
==14774==    by 0x100003259: main (main.c:30)
==14774==  Address 0x100e19e54 is 0 bytes after a block of size 4 alloc'd
==14774==    at 0x1000AF226: malloc (in /Users/mobouzar/.brew/Cellar/valgrind/3.15.0/lib/valgrind/vgpreload_memcheck-amd64-darwin.so)
==14774==    by 0x100004614: ft_strdup (ft_strdup.c:23)
==14774==    by 0x100003854: creat_rooms_array (sort_rooms.c:83)
==14774==    by 0x1000027F2: read_data (parse_.c:114)
==14774==    by 0x100003259: main (main.c:30)
==14774== 
==14774== 
==14774== 2265 errors in context 31 of 33:
==14774== Invalid read of size 1
==14774==    at 0x1000045B8: ft_strlen (ft_strlen.c:20)
==14774==    by 0x100003690: sort_rooms_array (sort_rooms.c:53)
==14774==    by 0x10000387E: creat_rooms_array (sort_rooms.c:86)
==14774==    by 0x1000027F2: read_data (parse_.c:114)
==14774==    by 0x100003259: main (main.c:30)
==14774==  Address 0x100e19e54 is 0 bytes after a block of size 4 alloc'd
==14774==    at 0x1000AF226: malloc (in /Users/mobouzar/.brew/Cellar/valgrind/3.15.0/lib/valgrind/vgpreload_memcheck-amd64-darwin.so)
==14774==    by 0x100004614: ft_strdup (ft_strdup.c:23)
==14774==    by 0x100003854: creat_rooms_array (sort_rooms.c:83)
==14774==    by 0x1000027F2: read_data (parse_.c:114)
==14774==    by 0x100003259: main (main.c:30)
==14774== 
==14774== 
==14774== 91082 errors in context 32 of 33:
==14774== Invalid read of size 1
==14774==    at 0x1000045B8: ft_strlen (ft_strlen.c:20)
==14774==    by 0x1000049D8: ft_strcmp (ft_strcmp.c:24)
==14774==    by 0x100003672: sort_rooms_array (sort_rooms.c:51)
==14774==    by 0x10000387E: creat_rooms_array (sort_rooms.c:86)
==14774==    by 0x1000027F2: read_data (parse_.c:114)
==14774==    by 0x100003259: main (main.c:30)
==14774==  Address 0x100e19e54 is 0 bytes after a block of size 4 alloc'd
==14774==    at 0x1000AF226: malloc (in /Users/mobouzar/.brew/Cellar/valgrind/3.15.0/lib/valgrind/vgpreload_memcheck-amd64-darwin.so)
==14774==    by 0x100004614: ft_strdup (ft_strdup.c:23)
==14774==    by 0x100003854: creat_rooms_array (sort_rooms.c:83)
==14774==    by 0x1000027F2: read_data (parse_.c:114)
==14774==    by 0x100003259: main (main.c:30)
==14774== 
--14774-- 
--14774-- used_suppression:      4 OSX1012:19-Leak /Users/mobouzar/.brew/Cellar/valgrind/3.15.0/lib/valgrind/default.supp:924 suppressed: 8,768 bytes in 4 blocks
--14774-- used_suppression:      8 OSX1012:17-Leak /Users/mobouzar/.brew/Cellar/valgrind/3.15.0/lib/valgrind/default.supp:906 suppressed: 3,872 bytes in 61 blocks
--14774-- used_suppression:      3 OSX1012:16-Leak /Users/mobouzar/.brew/Cellar/valgrind/3.15.0/lib/valgrind/default.supp:897 suppressed: 3,072 bytes in 48 blocks
--14774-- used_suppression:     15 OSX1012:10-Leak /Users/mobouzar/.brew/Cellar/valgrind/3.15.0/lib/valgrind/default.supp:839 suppressed: 2,179 bytes in 35 blocks
--14774-- used_suppression:      4 OSX1012:18-Leak /Users/mobouzar/.brew/Cellar/valgrind/3.15.0/lib/valgrind/default.supp:915 suppressed: 120 bytes in 4 blocks
--14774-- used_suppression:      1 OSX1012:dyld-5 /Users/mobouzar/.brew/Cellar/valgrind/3.15.0/lib/valgrind/default.supp:1283
--14774-- used_suppression:      2 OSX1012:dyld-4 /Users/mobouzar/.brew/Cellar/valgrind/3.15.0/lib/valgrind/default.supp:1275
--14774-- used_suppression:      1 OSX1012:dyld-3 /Users/mobouzar/.brew/Cellar/valgrind/3.15.0/lib/valgrind/default.supp:1267
==14774== 
==14774== ERROR SUMMARY: 109425 errors from 33 contexts (suppressed: 11 from 11)
