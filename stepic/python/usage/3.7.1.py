from xml.etree import ElementTree

tree = ElementTree.fromstring(input())

result = {
    "blue": 0,
    "green": 0,
    "red": 0, 
}

def evaluate(element, level):
    global result
    if (element.tag == "cube"):
        result[element.attrib["color"]] += level

    for child in element:
        evaluate(child, level + 1)

evaluate(tree, 1)

print("{red} {green} {blue}".format(**result))
