# Function to generate prefixes and suffixes
def generate_prefix_suffix(word):
    prefixes = set()
    suffixes = set()
    for i in range(3, len(word)):
        prefixes.add(word[:i])
        suffixes.add(word[i:])
    return prefixes, suffixes

# Read input values
n, m = map(int, input().split())
dictionary = {}
for _ in range(n):
    word = input().strip()
    prefixes, suffixes = generate_prefix_suffix(word)
    for prefix in prefixes:
        dictionary.setdefault(prefix[-1], []).append((prefix, word))
    for suffix in suffixes:
        dictionary.setdefault(suffix[0], []).append((word, suffix))

# Process potential blended words
for _ in range(m):
    potential_blended_word = input().strip()
    possible_prefixes = dictionary.get(potential_blended_word[0], [])
    possible_suffixes = dictionary.get(potential_blended_word[-1], [])

    result = "none"
    for prefix, prefix_word in possible_prefixes:
        for suffix, suffix_word in possible_suffixes:
            if prefix + suffix == potential_blended_word and prefix_word != suffix_word:
                if result == "none":
                    result = prefix_word + " " + suffix_word
                else:
                    result = "ambiguous"
                    break

    print(result)
