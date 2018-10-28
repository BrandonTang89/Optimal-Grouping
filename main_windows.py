import subprocess
m = dict()
reverse = dict()
counter = 0
output = open("input.in", "w")
print ("Translated Input---- ") 
with open("human_in.txt") as file:
    for line in file:
        line = line.strip()
        new_line = ""
        for word in line.split():
            if word.isdigit():
                new_line += word + " "
            elif word in m:
                new_line += str(m[word]) + " "
            else:
                m[word] = counter
                reverse[counter] = word
                counter += 1
                new_line += str(m[word]) + " "

        print (new_line)
        output.write(new_line + "\n")

output.close()
print ("Dictionary----")
print(m)

subprocess.call("seating_arrangement.exe")

output = open("human_out.txt", "w")
with open("output.out") as file:
    for line in file:
        line = line.strip()
        if line[0] == "-":
            output.write("\n" + "Group: " + line[1:] + "\n")
        else:
            output.write(reverse[int(line)]+"\n")

output.close()
