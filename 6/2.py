import re
src_sequence = ['attgttaacctg', 'attcg','atcgttaacctg','ggg','g']
print "Source sequence:\t",src_sequence
string = raw_input("Enter target sequence:\t  ")
target_sequence=string.split(',')

def detect_sequence(src_sequences,target_sequence):
    result = []
    for src in src_sequences:
        for target in target_sequence:
                if(len(src)==len(target)):
                	for i in range(len(target)):
                        	if src[:i]==target[:i] and src[i]!=target[i] and src[i+1:]==target[i+1:] :
                                         if(src not in result):
                                                result.append(src)
                                         break
                elif(abs(len(src)-len(target))==1):
                        found=re.search(src,target)
                        if found:
                                result.append(src)
			found=re.search(target,src)
			if found:
                                result.append(src)

    print "Result:\t\t\t",result
    return result

detect_sequence(src_sequence,target_sequence)

