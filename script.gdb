# Set the breakpoint
b a23.cpp:26

# Run the program with input redirection
r < mobydick.txt

display wordCount
display palavraFiltrada

# Set the loop counter
set $i = 0

# Start the loop
while $i < 110731
c
set $i = $i + 1
end

# b separaPalavras
# display palavra
# display it_beginWord
# display it_endWord