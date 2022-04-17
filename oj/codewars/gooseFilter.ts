export function gooseFilter (birds: string[]): string[] {
    const geese: string[] = ["African", "Roman Tufted", "Toulouse", "Pilgrim", "Steinbacher"];
    // return an array containing all of the strings in the input array except those that match strings in geese
    let res: string[] = [];
    for(const bird of birds) {
        if(!geese.includes(bird)) {
            res.push(bird);
        }
    }
    return res;
}

export function gooseFilter1 (birds: string[]): string[] {
    const geese: string[] = ["African", "Roman Tufted", "Toulouse", "Pilgrim", "Steinbacher"];
    // return an array containing all of the strings in the input array except those that match strings in geese
    return birds.filter(bird => !geese.includes(bird));
}