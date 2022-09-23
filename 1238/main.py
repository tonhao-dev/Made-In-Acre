for i in range(int(input())):
  new_word = ''
  first_word, second_word = input().split(' ')

  first_arr = list(first_word) 
  second_arr = list(second_word)
  
  index = 0
  while index < len(first_arr) and index < len(second_arr):
    print(first_arr[index], end='')
    print(second_arr[index], end='')

    index += 1

  if (len(first_arr) > index):
    print(''.join(first_arr[index:]))
  elif len(second_arr) > index:
    print(''.join(second_arr[index:]))
  else: 
    print()