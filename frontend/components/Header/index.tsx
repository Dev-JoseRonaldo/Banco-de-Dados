export default function Header({ user }: { user: string }) {
  return (
    <header className="bg-primary text-white p-4 text-center text-xl font-bold">
      LkCIn - Olá, {user}!
    </header>
  );
}
