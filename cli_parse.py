def cli_parse(args : list[str]):
  flags = {}
  regular = []

  is_flag = lambda s: s[0] == '-' and len(s) > 1

  def split_flag(s : str):
    p = s.find(':')
    if p > -1:
      return (s[1:p], s[p+1:])
    else:
      return (s[1:], True)

  for arg in args:
    if is_flag(arg):
      k, v = split_flag(arg)
      flags[k] = v
    else:
      regular.append(arg)

  return flags, regular

