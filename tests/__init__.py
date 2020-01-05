from pathlib import Path


def here(p: str) -> Path:
    return Path(__file__).parent.joinpath(p).resolve()
