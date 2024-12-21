cmake_minimum_required(VERSION 3.10)
project(final_exams C)

set(CMAKE_C_STANDARD 17)

add_executable(sorted.c sorted.c)
add_executable(bsearch.c bsearch.c)
add_executable(gobang.c gobang.c)
add_executable(lineup.c lineup.c)

add_executable("bubble-sort.c" "bubble-sort.c")
add_executable("checker.c" checker.c)
add_executable("whac-a-mole.c" whac-a-mole.c)
add_executable("unrolled-linked-list.c" unrolled-linked-list.c)

add_executable(merge.c merge.c)
add_executable(b-ternary.c b-ternary.c)
add_executable(recog.c recog.c)
add_executable(memory.c memory.c)

add_executable(ddl.c ddl.c)
add_executable(rolling.c rolling.c)
add_executable(counting.c counting.c)
add_executable(rna.c rna.c)